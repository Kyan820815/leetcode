//--- Q: 0360. Sort Transformed Array

//--- method 1: two pointer
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int left = 0, right = nums.size()-1, idx, dir, d;
        vector<int> res(nums.size());
        if (a < 0) {
            idx = 0, dir = 1, d = -1;
        } else {
            idx = nums.size()-1, dir = -1, d = 1;
        }
        while (left <= right) {
            int lv = compute(nums[left], a, b, c);
            int rv = compute(nums[right], a, b, c);
            if (lv*d < rv*d) {
                res[idx] = rv;
                --right;
            } else {
                res[idx] = lv;
                ++left;
            }
            idx += dir;
        }
        return res;
    }
    int compute(int x, int a, int b, int c) {
        return a*x*x+b*x+c;
    }
};