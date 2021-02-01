//--- Q: 930. Binary Subarrays With Sum

//--- method 1: sliding window one pass
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, prefix = 0, left = 0, right = 0;
        while (right < nums.size()) {
            k -= nums[right]&1;
            if (k < 0) {
                while (!(nums[left++]&1));
                k = prefix = 0;
            }
            while (left < right && !(nums[left]&1)) {
                ++prefix, ++left;
            }
            if (!k) { 
                res += prefix+1;
            }
            ++right;
        }
        return res;
    }
};