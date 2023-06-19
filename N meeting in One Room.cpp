// TC = O(N log N)
// SC = O(N)


class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.

    // Custom comparator function to sort the meetings by their end time
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        // Create a vector of pairs to store the start and end times of meetings
        vector<pair<int, int>> v;
        int meet = 1; // Variable to store the count of meetings

        // Store the start and end times of meetings in the vector
        for (int i = 0; i < n; i++)
        {
            v.push_back({start[i], end[i]});
        }

        // Sort the meetings based on their end times in ascending order
        sort(v.begin(), v.end(), cmp);

        // Iterate through the sorted meetings and check for overlapping meetings
        for (int i = 1; i < n; i++)
        {
            if (v[i - 1].second < v[i].first)
            {
                meet++; // Increment the meeting count if there is no overlap
            }
            else
            {
                v[i] = v[i - 1]; // If there is an overlap, consider the previous meeting
            }
        }

        return meet; // Return the maximum number of meetings that can be performed
    }
};
