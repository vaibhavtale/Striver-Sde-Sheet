// TC = O(NlogN)
// SC = O(N)

class Solution {
public:
    // Custom comparator function for sorting intervals
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first <= b.first;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        // Sort the intervals based on the start time
        sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        pq.push({intervals[0][0], intervals[0][1]});

        // Merge overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            auto temp = pq.top();
            pq.pop();

            int st = temp.first;
            int en = temp.second;

            if (intervals[i][0] <= en) {
                // Extend the current interval
                pq.push({st, max(intervals[i][1], en)});
            } else {
                // Add the current interval to the priority queue
                pq.push({intervals[i][0], intervals[i][1]});
                pq.push(temp);
            }
        }

        // Store the merged intervals in the result vector
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            vector<int> mergedInterval = {temp.first, temp.second};
            mergedIntervals.push_back(mergedInterval);
        }

        return mergedIntervals;
    }
};
