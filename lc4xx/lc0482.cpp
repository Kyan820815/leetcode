//--- Q: 482. License Key Formatting

//--- method 1: linear processing
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int cnt = 0;
        for (int i = S.size()-1; i >= 0; --i) {
            if (S[i] != '-') {
                res += toupper(S[i]);
                if (++cnt == K) {
                    cnt = 0;
                    res += '-';
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