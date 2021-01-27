//--- Q: 1180. Count Substrings with Only One Distinct Letter

//--- method 1: linear search
class Solution {
public:
    int countLetters(string S) {
        int last = 0, res = 0;
        char lastc = S[0];
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] != lastc) {
                lastc = S[i];
                last = i;
            }
            res += i-last+1;
        }
        return res;
    }
};