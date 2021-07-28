//--- Q: 0482. License Key Formatting

//--- method 1: linear processing
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        for (int i = s.size()-1, j = 0; i >= 0; --i) {
            if (s[i] != '-') {
                auto ch = islower(s[i]) ? s[i]^32 : s[i];
                res += ch;
                if (++j == k) {
                    res.push_back('-');
                    j = 0;
                }
            }
        }
        if (res.back() == '-') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};