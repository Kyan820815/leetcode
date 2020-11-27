//--- Q: 1049. Last Stone Weight II

//--- method 1: O(n^2) time
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp;
        int sum = 0;
        for (int i = 0; i < stones.size(); ++i)
        	sum += stones[i];
        dp = vector<int>(sum/2 + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < stones.size(); ++i)
        {
        	for (int j = sum/2; j >= stones[i]; --j)
        	{
        		if (dp[j-stones[i]])
        			dp[j] = 1;
        	}
        }
        for (int i = sum/2; i > 0; --i)
        {
        	if (dp[i])
        		return sum - i - i;
        }
        return 0;
    }
};

//--- method 2: O(n) time bit set
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        bitset<1501> dp(1);
	    for (int i = 0; i < stones.size(); ++i)
			sum += stones[i];
        for (int i = 0; i < stones.size(); ++i)
        {
        	dp |= dp << stones[i];
        }
        for (int i = sum/2; i > 0; --i)
        {
        	if (dp[i])
        		return sum - i - i;
        }
        return 0;
    }
};