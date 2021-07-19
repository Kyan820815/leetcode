//--- Q: 0389. Find the Difference

//--- method 1: bit operation
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (auto &ch: s) {
            res ^= ch;
        }
        for (auto &ch: t) {
            res ^= ch;
        }
        return res;
    }
};