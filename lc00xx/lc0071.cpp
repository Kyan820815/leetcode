//--- Q: 0071. Simplify Path

//--- method 1: stack
class Solution {
public:
    string simplifyPath(string path) {
        string res = "", file = "";
        vector<string> sk;
        int idx = 0;
        while (idx <= path.size()) {
            if (idx == path.size() || path[idx] == '/') {
                if (file == ".." && sk.size()) {
                    sk.pop_back();
                } else if (file.size() && file != "." && file != "..") {
                    sk.push_back(file);
                }
                file = "";
            } else {
                file += path[idx];
            }
            ++idx;
        }
        for (int i = 0; i < sk.size(); ++i) {
            res += "/" + sk[i];
        }
        return !res.size() ? "/" : res;
    }
};