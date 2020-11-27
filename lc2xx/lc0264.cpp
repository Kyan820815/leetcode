//--- Q: 264. Ugly Number II

//--- method 1: dp find the first index greater than now
class Solution {
public:
    int nthUglyNumber(int n) {
    	vector<int> dp(1,1);
    	int two, three, five;
    	two = three = five = 0;
    	for (int i = 1; i < n; ++i)
    	{
    		int now = min(dp[two]*2, min(dp[three]*3, dp[five]*5));
    		dp.push_back(now);
    		while(dp[two]*2 <= now)
    			two++;	
    		while(dp[three]*3 <= now)
    			three++;	
    		while(dp[five]*5 <= now)
    			five++;	
    	}
    	return dp.back();
    }
};