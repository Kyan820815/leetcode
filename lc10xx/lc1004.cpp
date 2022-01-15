//--- Q: 1004. Max Consecutive Ones III

//--- method 1: sliding window
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0, res = 0;
        while (right < n) {
            k -= !nums[right];
            while (k < 0) {
                k += !nums[left++];
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};

//--- method 2: sliding window with another thought
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size();
        while (right < n) {
            k -= !nums[right];
            if (k < 0 && !nums[left++]) {
                ++k;
            }
            ++right;
        }
        return right-left;
    }
};