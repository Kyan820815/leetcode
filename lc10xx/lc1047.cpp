//--- Q: 1047. Remove All Adjacent Duplicates In String

//--- method 1: stack, better
class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for (auto &ch: s) {
            if (res.size() && res.back() == ch) {
                res.pop_back();
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};