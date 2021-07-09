//--- Q: 0209. Minimum Size Subarray Sum

//--- method 1: O(n), one pass
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, n = nums.size(), res = INT_MAX, sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                res = min(res, right-left+1);
                sum -= nums[left++];
            }
            ++right;
        }
        return res == INT_MAX ? 0 : res;
    }
};

//--- method 2: O(nlogn), binrary search
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> sum = {0};
        for (auto &num: nums) {
            sum.push_back(sum.back()+num);
        }
        int res = INT_MAX, n = nums.size();
        for (int i = 1; i <= n; ++i) {
            int left = i, right = n;
            while (left < right) {
                int mid = left + (right-left)/2;
                if (sum[mid]-sum[i-1] < target)  {
                    left = mid+1;
                } else {
                    right = mid;
                }
            }
            if (sum[left]-sum[i-1] >= target) {
                res = min(res, left-i+1);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

