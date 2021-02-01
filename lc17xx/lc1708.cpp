//--- Q: 1708. Largest Subarray Length K

//--- method 1: find from 0 to n-k-1
class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), start = n-k;
        for (int i = 0; i < n-k; ++i) {
            if (nums[i] > nums[start]) {
                start = i;
            }
        }
        return vector<int>(nums.begin()+start, nums.begin()+start+k);
    }
};

//--- follow up: two pointer
class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        nums = {3,1,3,2,3,1}, k = 2;
        nums = {3,1,3,1,3,2,3}, k = 3;
        nums = {4,3,4,3,4,3,5}, k = 5;
        nums = {0,0,2,1}, k = 2;
        nums = {4,4,4,4,5}, k = 3;
        int n = nums.size(), l = 0, r = 1, cnt = 0;
        while (r+k-1 < n && r+cnt < n) {
            if (nums[l+cnt] == nums[r+cnt]) {
                ++cnt;
                continue;
            } else if (nums[l+cnt] > nums[r+cnt]) {
                r += cnt+1;
            } else {
                l = r;
                r = l+1;
            }
            cnt = 0;
        }
        return vector<int>(nums.begin()+l, nums.begin()+l+k);
    }
};