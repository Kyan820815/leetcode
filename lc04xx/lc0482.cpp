//--- Q: 482. License Key Formatting

//--- method 1: linear processing
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        int cnt = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] != '-') {
                if (cnt == k) {
                    res.push_back('-');
                    cnt = 0;
                }
                res.push_back(toupper(s[i]));
                ++cnt;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};