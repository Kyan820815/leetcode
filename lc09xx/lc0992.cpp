//--- Q: 0992. Subarrays with K Different Integers

//--- method 1: sliding window one pass
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res = 0, left = 0, right = 0, prefix = 0, n = nums.size();
        vector<int> cnt(n+1, 0);
        while (right < n) {
            k -= ++cnt[nums[right]] == 1;
            if (k < 0) {
                while (left < right && --cnt[nums[left++]]);
                k = 0, prefix = 0;
            }
            while (left < right && cnt[nums[left]] > 1) {
                --cnt[nums[left++]];
                ++prefix;
            }
            if (!k) {
                res += prefix+1;
            }
            ++right;
        }
        return res;
    }
};

//--- method 2: sliding window two pass
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums, k) - atmostk(nums, k-1);
    }
    int atmostk(vector<int> &nums, int k) {
        int res = 0, left = 0, right = 0, n = nums.size();
        vector<int> cnt(n+1, 0);
        while (right < n) {
            k -= ++cnt[nums[right]] == 1;
            if (k < 0) {
                while (left <= right && --cnt[nums[left++]]);
                k = 0;
            }
            res += right-left+1;
            ++right;
        }
        return res;
    }
};
