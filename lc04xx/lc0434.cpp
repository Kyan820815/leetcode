//--- Q: 0434. Number of Segments in a String

//--- method 1: linear search
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && (i+1 == s.size() || s[i+1] == ' ')) {
                ++res;
            }
        }
        return res;
    }
};