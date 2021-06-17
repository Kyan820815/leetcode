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

//--- method 2: other view of stack
class Solution {
public:
    string simplifyPath(string path) {
        string res = "", dir = "";
        vector<string> sk;
        int i = 0;
        while (i <= path.size()) {
            if (i == path.size() || path[i] == '/') {
                if (dir == "..") {
                    if (sk.size()) {
                        sk.pop_back();
                    }
                } else if (dir.size() && dir != ".") {
                    sk.push_back(dir);
                }
                dir = "";
            } else {
                dir.push_back(path[i]);
            }
            ++i;
        }
        for (int i = 0; i < sk.size(); ++i) {
            res += "/" + sk[i];
        }
        return !res.size() ? "/" : res;
    }
};