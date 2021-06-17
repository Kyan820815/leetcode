//--- Q: 91. Decode Ways

//--- method 1: dp iteration, O(n) space
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '0')
                dp[i] += (i > 0 ? dp[i-1] : 1);
            if (i > 0 && (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6'))
                dp[i] += (i > 1 ? dp[i-2] : 1);
        }
        return dp[s.size()-1];
    }
};

//--- mehtod 2: O(1) space
class Solution {
public:
    int numDecodings(string s) {
        int i_1 = 1, i_2 = 1;
        for (int i = 0; i < s.size(); ++i) {
            int tmp = 0;
            if (s[i] != '0') {
                tmp += i_1;
            }
            if (i > 0 && (s[i-1] == '1' || s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                tmp += i_2;
            }
            i_2 = i_1;
            i_1 = tmp;
        }
        return i_1;
    }
};