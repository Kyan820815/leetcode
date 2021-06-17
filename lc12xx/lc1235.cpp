//--- Q: 1235. Maximum Profit in Job Scheduling

//--- method 1: map with dp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = profit.size();
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp;
        dp[0] = 0;
        for (auto &job: jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second+job[2];
            if (cur > dp.rbegin()->second) {
                dp[job[0]] = cur;
            }
        }
        return dp.rbegin()->second;
    }
};
