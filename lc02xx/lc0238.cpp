//--- Q: 238. Product of Array Except Self

//--- method 1: O(n) time, O(n) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> res;
        int sum = 1;
        for (int i = nums.size()-1; i > 0; --i)
        {
        	sum = sum * nums[i];
        	right[i-1] = sum;
        }
        sum = 1;
        for (int i = 0; i < nums.size()-1; ++i)
        {
        	sum *= nums[i];
        	left[i+1] = sum;
        }
        for (int i = 0; i < nums.size(); ++i)
        	res.push_back(left[i]*right[i]);
        return res;
    }
};

//--- method 2: O(n) time, O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int left, right, end = nums.size()-1;
        left = right = 1;
        for (int start = 0; start < nums.size(); ++start, --end)
        {
        	res[start] *= left;
        	left *= nums[start];
        	res[end] *= right;
        	right *= nums[end];
        }
        return res;
    }
};