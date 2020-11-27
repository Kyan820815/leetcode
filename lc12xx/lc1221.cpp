//--- Q: 1221. Split a String in Balanced Strings

//--- method 1: linear one pass
class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
             (s[i] == 'L') ? ++l : --l;
            if (!l) {
                ++res;
            }
        }
        return res;
    }
};