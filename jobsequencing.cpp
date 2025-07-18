class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;

        // Step 1: Pair profits with deadlines
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Step 2: Sort by profit in descending order
        sort(jobs.rbegin(), jobs.rend());

        // Step 3: Find maximum deadline to limit our time slots
        int maxDeadline = *max_element(deadline.begin(), deadline.end());

        // Step 4: Initialize time slots
        vector<int> slot(maxDeadline + 1, -1);  // index 0 unused

        int totalProfit = 0, countJobs = 0;

        // Step 5: Greedily assign jobs
        for (int i = 0; i < n; i++) {
            int d = jobs[i].second;
            int p = jobs[i].first;

            // Find a free slot for this job (from d to 1)
            for (int j = d; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;  // job i scheduled
                    totalProfit += p;
                    countJobs++;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};