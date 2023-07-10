// TC = O(m + n^3)
// SC = O(m + n^2)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(int ind, string& s, unordered_map<string, bool>& h, vector<string>& v, vector<string>& res) {
    // Base case: reached the end of the string
    if (ind >= s.length()) {
        // If the current combination is not empty, construct a string and add it to the results
        if (!v.empty()) {
            string temp = "";
            for (auto it : v) {
                temp += it;
                temp += ' ';
            }
            temp.pop_back();
            res.push_back(temp);
        }
        return;
    }
    
    // Recursive case: explore all possible substrings starting from the current index
    for (int i = ind; i < s.length(); i++) {
        string substr = s.substr(ind, i - ind + 1);
        // If the current substring is present in the dictionary, add it to the current combination and continue exploring
        if (h.count(substr) && h[substr]) {
            v.push_back(substr);
            solve(i + 1, s, h, v, res);
            v.pop_back();
        }
    }
}

vector<string> wordBreak(string& s, vector<string>& d) {
    unordered_map<string, bool> h;
    vector<string> v;
    vector<string> res;
    
    // Preprocess the dictionary words into a hashmap for efficient lookup
    for (auto it : d) {
        h[it] = true;
    }
    
    // Call the solve function to find all valid word combinations
    solve(0, s, h, v, res);
    
    return res;
}

int main() {
    string s = "examplestring";
    vector<string> dictionary = { "example", "string" };
    vector<string> result = wordBreak(s, dictionary);
    
    // Print the obtained word combinations
    for (const auto& str : result) {
        cout << str << endl;
    }
    
    return 0;
}
