//--- Q: 1641. Count Sorted Vowel Strings

//--- method 1: O(5) space dp
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        for (int i = 2; i <= n; ++i) {
            vector<int> tmp = {1};
            int last = dp[0];
            for (int j = 1; j < 5; ++j) {
                last += dp[j];
                tmp.push_back(last);
            }
            dp = tmp;
        }
        int res = 0;
        for (int i = 0; i < 5; ++i) {
            res += dp[i];
        }
        return res;
    }
};

// method 2: O(n*5) space dp
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n, vector<int>(5, 1));
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < 5; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        int res = 0;
        for (auto &v: dp[n-1]) {
            res += v;
        }
        return res;
    }
};
