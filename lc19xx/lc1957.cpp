//--- Q: 1957. Delete Characters to Make Fancy String

//--- method 1: compare with last two
class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (i < 2 || s[i] != s[i-1] || s[i] != s[i-2]) {
                res += s[i];
            }
        }
        return res;
    }
};