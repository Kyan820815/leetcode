//--- Q: 0673. Number of Longest Increasing Subsequence

//--- method 1: O(n^2)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxcnt, maxlen;
        vector<int> cnt(n, 1), len(n, 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (len[j]+1 > len[i]) {
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    } else if (len[j]+1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (maxlen < len[i]) {
                maxlen = len[i];
                maxcnt = cnt[i];
            } else if (maxlen == len[i]) {
                maxcnt += cnt[i];
            }
        }
        return maxcnt;
    }
};