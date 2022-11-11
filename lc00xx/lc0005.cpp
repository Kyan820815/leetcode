//--- Q: 0005. Longest Palindromic Substring
//--- last written: 2022/11/01

//--- method 1: linear search
class Solution {
public:
    string longestPalindrome(string s) {
        int idx = 0, maxlen = 1, start = 0;
        while (idx < s.size()) {
            int left = idx-1, right;
            if (s.size()-idx < maxlen/2) {
                break;
            }
            while (idx < s.size()-1 && s[idx] == s[idx+1]) {
                ++idx;
            }
            right = ++idx;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left, ++right;
            }
            if (right-left-1 > maxlen) {
                maxlen = right-left-1;
                start = left+1;
            }
        }
        return s.substr(start, maxlen);
    }
};

//--- method 2: dynamic programming
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, res = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                if ((j-i == 1 || dp[i+1][j-1]) && s[i] == s[j]) {
                    dp[i][j] = 1;
                    if (res < j-i+1) {
                        res = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, res);
    }
};
