//--- Q: Delete and Earn

//--- method 1: dp, O(n)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    	if (!nums.size()) return 0;
        vector<int> cnt(10001,0);
        for (int i = 0; i < nums.size(); ++i)
        	cnt[nums[i]] += nums[i];
        for (int i = 2; i <= 10000; ++i)
        	cnt[i] = max(cnt[i-1], cnt[i-2]+cnt[i]);
        return cnt[10000];
    }
};

//--- method 2: O(1) space
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> list(100001,0);
        int minv = INT_MAX, maxv = INT_MIN;
        int oddmax = 0, evenmax = 0;
        for (int i = 0; i < nums.size(); ++i) {
            minv = min(minv, nums[i]);
            maxv = max(maxv, nums[i]);
            list[nums[i]] += nums[i];
        }
        for (int i = minv; i <= maxv; ++i) {
            if ((i & 1) == 0)
                evenmax = max(oddmax, evenmax+list[i]);
            else
                oddmax = max(evenmax, oddmax+list[i]);
        }
        int res = max(evenmax, oddmax);
        return res;
    }
};