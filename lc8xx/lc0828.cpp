//--- Q: 0828. Count Unique Characters of All Substrings of a Given String

//--- method 1: dynamic programming
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size(), cur = 0, res = 0;
        vector<int> lastPos(128, -1), contri(128, 0);
        for (int i = 0; i < s.size(); ++i) {
            cur -= contri[s[i]];
            contri[s[i]] = i-lastPos[s[i]];
            cur += contri[s[i]];
            lastPos[s[i]] = i;
            res += cur;
        }
        return res;
    }
};