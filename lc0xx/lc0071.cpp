//--- Q: 71. Simplify Path

//--- method 1: stack
class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        vector<string> sk;
        for (int i = 0; i < path.size();) {
            if (path[i] != '/') {
                string dir = "";
                while (i < path.size() && path[i] != '/') {
                    dir += path[i++];
                }
                if (dir == "..") {
                    if (sk.size()) {
                        sk.pop_back();
                    }
                } else if (dir != ".") {
                    sk.push_back(dir);
                }
            } else {
                ++i;
            }
        }
        for (int i = 0; i < sk.size(); ++i) {
            res += "/" + sk[i];
        }
        return !res.size() ? "/" : res;
    }
};