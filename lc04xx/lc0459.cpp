//--- Q: 459. Repeated Substring Pattern

//--- method 1: next of KMP
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int j = -1, i = 0, n = s.size();
        vector<int> dp(n+1, -1);
        while (i < n)
        {
            if (j == -1 || s[i] == s[j])
                dp[++i] = ++j;
            else j = dp[j];
        }
        return dp[n] > 0 && n%(n-dp[n]) == 0;
    }
};

//--- method 2: use lenth to count repeated subdstring
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = n/2; i >= 1; --i) {
            if (n % i == 0 && s.substr(i) == s.substr(0, n-i)) {
                return true;
            }
        }
        return false;
    }
};