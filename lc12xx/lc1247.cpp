//--- Q: 1247. Minimum Swaps to Make Strings Equal

//--- method 1: one pass, find pattern
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return -1;
        }
        int n = s1.size(), xy = 0, yx = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == 'x' && s2[i] == 'y') {
                ++xy;
            } else if (s1[i] == 'y' && s2[i] == 'x') {
                ++yx;
            }
        }
        res += (xy/2 + yx/2);
        
        if (xy%2 + yx%2 == 1) {
            return -1;
        } else {
            return res + xy%2 + yx%2;
        }
    }
};