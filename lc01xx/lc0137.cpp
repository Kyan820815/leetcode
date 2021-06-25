//--- Q: 137. Single Number II

//--- method 1: bit operation, O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones, twos, threes;
        ones = twos = threes = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
        	twos = twos | (ones & nums[i]);
        	ones = ones ^ nums[i];
        	threes = ~(ones & twos);
        	ones = ones & threes;
        	twos = twos & threes;
        }
        return ones;
    }
};

//--- method 2: 32-bit check, O(n^2)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int ans = 0;
    	for	(int i = 0; i < 32; ++i)
    	{
    		int bit = 1 << i, cnt = 0;
    		for (int j = 0; j < nums.size(); ++j)
    			if ((bit & nums[j]) != 0) cnt++;
    		if (cnt % 3 != 0)
    			ans += bit;
    	}
    	return ans;
    }
};