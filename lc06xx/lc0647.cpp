//--- Q: 0647. Palindromic Substrings

//--- method 1: dp, O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = n;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                if ((j-i == 1 || dp[i+1][j-1]) && s[i] == s[j]) {
                    ++res;
                    dp[i][j] = 1;
                }
            }
        }
        return res;
    }
};

//--- method 2: O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = n;
        for (int i = 0; i < s.size();) {
            int right = i, left = i-1;
            while (right < n-1 && s[right] == s[right+1]) {
                ++right;
                res += right-i;
            }
            i = ++right;
            while (left >= 0 && right < n && s[left] == s[right]) {
                ++res;
                --left, ++right;
            }
        }
        return res;
    }
};