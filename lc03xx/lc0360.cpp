//--- Q: 0360. Sort Transformed Array

//--- method 1: two pointer
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size());
        int start = a >= 0 ? nums.size()-1 : 0;
        int dir = a >= 0 ? -1 : 1;
        int left = 0, right = nums.size()-1;
        for (; left <= right;) {
            if (a >= 0) {
                res[start] = func(a,b,c,nums[left]) > func(a,b,c,nums[right]) ? func(a,b,c,nums[left++]) : func(a,b,c,nums[right--]);
            } else {
                res[start] = func(a,b,c,nums[left]) < func(a,b,c,nums[right]) ? func(a,b,c,nums[left++]) : func(a,b,c,nums[right--]);
            }
            start += dir;
        }
        return res;
    }
    int func(int a, int b, int c, int v) {
        return a*v*v + b*v + c;
    }
};