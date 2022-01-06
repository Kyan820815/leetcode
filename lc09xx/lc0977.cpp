//--- Q: 0977. Squares of a Sorted Array

//--- method 1: double pointer 
class Solution {
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size()-1, idx = nums.size()-1;
        vector<int> res(nums.size(), 0);
        while (left <= right) {
            int sqleft = nums[left]*nums[left], sqright = nums[right]*nums[right];
            if (sqleft > sqright) {
                res[idx--] = sqleft;
                ++left;
            } else {
                res[idx--] = sqright;
                --right;
            }
        }
        return res;
    }
};

//--- method 2:
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sk, res;
        for (auto &num: nums) {
            while (sk.size() && sk.back() < abs(num)) {
                res.push_back(sk.back()*sk.back());
                sk.pop_back();
            }
            sk.push_back(abs(num));
        }
        while (sk.size()) {
            res.push_back(sk.back()*sk.back());
            sk.pop_back();
        }
        return res;
    }
};