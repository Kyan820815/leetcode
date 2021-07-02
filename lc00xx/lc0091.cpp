//--- Q: 0091. Decode Ways

//--- method 1: dp iteration, O(n) space
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] > '0') {
                dp[i] += i ? dp[i-1] : 1;
            }
            if (i && (s[i-1] == '1' || s[i-1] == '2' && '0' <= s[i] && s[i] <= '6')) {
                dp[i] += i > 1 ? dp[i-2] : 1;
            }
        }
        return dp.back();
    }
};

//--- mehtod 2: O(1) space
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), last1 = 1, last2 = 1;
        for (int i = 0; i < s.size(); ++i) {
            int tmp = 0;
            if (s[i] > '0') {
                tmp += last1;
            }
            if (i && (s[i-1] == '1' || s[i-1] == '2' && '0' <= s[i] && s[i] <= '6')) {
                tmp += last2;
            }
            last2 = last1;
            last1 = tmp;
        }
        return last1;
    }
};