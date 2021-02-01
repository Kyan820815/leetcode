//--- Q: 1358. Number of Substrings Containing All Three Characters

//--- method 1: one pass sliding window
class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0, n = s.size(), prefix = 0, res = 0, cnt = 3;
        vector<int> type(3, 0);
        while (right < n) {
            if (++type[s[right]-'a'] == 1) {
                --cnt;
            }
            while (left < right && type[s[left]-'a'] > 1) {
                --type[s[left]-'a'];
                ++left, ++prefix;
            }
            if (!cnt) {
                res += prefix + 1;
            }
            ++right;
        }
        return res;
    }
};