// TC = O(N log N)
// SC = O(N)

/*
struct Job 
{ 
    int id;     // Job Id 
    int dead;   // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
public:
    // Function to compare two jobs based on their profit and deadline
    static bool cmp(Job &a, Job &b)
    {
        if(a.profit == b.profit)
            return a.dead > b.dead;
        return a.profit > b.profit;
    }
    
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int jobs = 0;        // Count of scheduled jobs
        int maxProfit = 0;   // Total profit
        
        // Sort the jobs in descending order based on their profit and deadline
        sort(arr, arr+n, cmp);
        
        // Create a vector to track the availability of each day
        vector<bool> workDay(n+1, false);
        
        // Iterate over each job
        for(int i=0; i<n; i++)
        {
            int date = arr[i].dead;   // Deadline of the current job
            
            // Find an available day before the deadline
            while(date > 0)
            {
                // If the day is available, schedule the job on that day
                if(!workDay[date])
                {
                    maxProfit += arr[i].profit;     // Add the profit of the scheduled job
                    jobs++;                         // Increment the count of scheduled jobs
                    workDay[date] = true;           // Mark the day as scheduled
                    break;
                }
                date--;
            }
        }
        
        // Create a vector to store the count of scheduled jobs and the total profit
        vector<int> v(2);
        v[0] = jobs;
        v[1] = maxProfit;
        
        return v;
    } 
};
