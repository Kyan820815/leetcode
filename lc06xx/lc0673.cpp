//--- Q: 673. Number of Longest Increasing Subsequence

//--- method 1: dp, O(nlogn)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<pair<int,int>>> dp;
        int max_len = 0;
        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = 0, right = dp.size()-1;
            while(left < right)
            {
                int mid = (left+right)/2;
                if (dp[mid].back().first < nums[i])
                    left = mid+1;
                else 
                    right = mid;
            }
            int last;
            
            if (dp.size() > 0 && dp[left].back().first < nums[i])
                last = left;
            else
                last = left-1;

            int acc_cnt = 1;
            if (last >= 0)
            {
                int dpl = 0, dpr = dp[last].size()-1;
                while (dpl < dpr)
                {
                    int mid = (dpl+dpr)/2;

                    if (dp[last][mid].first < nums[i])
                        dpr = mid;
                    else 
                        dpl = mid+1;
                }
                acc_cnt = dp[last].back().second;
                acc_cnt -= (dpl == 0) ? 0 : dp[last][dpl-1].second;
            }
            if (dp.size() == 0 || last == left)
                dp.push_back({{nums[i], acc_cnt}});
            else
                dp[left].push_back({nums[i], dp[left].size()==0 ? acc_cnt : dp[left].back().second + acc_cnt});
        }
        return dp.back().back().second;
    }
};

//--- method 2: O(n^2)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> len(nums.size(), 1);
        int left, right, max_len, g_max_len = 0;
        int cnt;
        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            max_len = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    if (max_len < dp[j]+1)
                    {
                        max_len = dp[j]+1;
                        len[i] = len[j];                        
                    }
                    else if (max_len == dp[j]+1)
                        len[i] += len[j];
                }
            }
            dp[i] = max_len;
            if (max_len > g_max_len)
            {
                g_max_len = max_len;
                cnt = len[i];
            }
            else if (max_len == g_max_len)
                cnt += len[i];
        }
        return cnt;
    }
};