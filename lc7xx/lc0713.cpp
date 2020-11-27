//--- Q: 713. Subarray Product Less Than K

//--- method 1: two pointer, one pass
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int sum = 1, res = 0;
        if (k <= 0) return 0;

        while (right < nums.size())
        {
        	sum *= nums[right];
        	while (left <= right && sum >= k)
        		sum /= nums[left++];
        	res += (right-left)+1;
        	right++;
        }
        return res;
    }
};