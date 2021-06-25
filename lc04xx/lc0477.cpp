//--- Q: 477. Total Hamming Distance

//--- method 1: 32bit operation, O(n)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
    	int cnt = 0;
        for (int i = 0; i < 32; ++i)
        {
        	int ones = 0;
        	for (int j = 0; j < nums.size(); ++j)
        	{
        		if (nums[j] & (1 << i))
        			ones++;
        	}
        	cnt += (nums.size()-ones)*ones;
        }
        return cnt;
    }
};