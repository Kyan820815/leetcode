//--- Q: 0161. One Edit Distance

//--- method 1: consider delete, replace
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() < t.size()) {
            return isOneEditDistance(t, s);
        }
        int i = 0, j = 0, sl = s.size(), tl = t.size(), times = 1;
        while (i <= sl || j <= tl) {
            if (i == sl && j == tl) {
                break;
            }
            if (j == tl || s[i] != t[j]) {
                if (!times) {
                    return false;
                }
                --times;
                if (s.size() == t.size()) {
                    ++j;
                }
                ++i;
            } else {
                ++i, ++j;
            }
        }
        return !times;
    }
};