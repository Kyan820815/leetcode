//--- Q: 583. Delete Operation for Two Strings

//--- method 1: dp iteration, O(n) space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        if (!l1 && !l2) return 0;
        else if (!l1) return l2;
        else if (!l2) return l1;
        vector<int> dp(l2, 0);
        int last, pre;
        for (int i = 0; i < l1; ++i)
        {
        	for (int j = 0; j < l2; ++j)
        	{
                pre = dp[j];
        		if (word1[i] == word2[j])
        			dp[j] = ((i == 0 || j == 0) ? 0 : last) + 1;
        		else
					dp[j] = max((i == 0 ? 0 : dp[j]), (j == 0 ? 0 : dp[j-1]));
                last = pre;
        	}
        }
        return l1-dp[l2-1] + l2-dp[l2-1];
    }
};