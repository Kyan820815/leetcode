//--- Q: 0161. One Edit Distance

//--- method 1: consider delete, replace, insert
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() == 1 && !t.size() || t.size() == 1 && !s.size()) {
            return true;
        }
        int i = 0, j = 0, op = 0;
        while (i <= s.size() || j <= t.size()) {
            if (i == s.size() && j == t.size()) {
                break;
            }
            if (i == s.size() || j == t.size() || s[i] != t[j]) {
                if (!op) {
                    op = 1;
                    if (s.size() < t.size()) {
                        ++j;
                    } else if (s.size() == t.size()) {
                        ++i, ++j;
                    } else {
                        ++i;
                    }
                } else {
                    return false;
                }
            } else {
                ++i, ++j;
            }
        }
        return op == 1;
    }
};

//--- method 2: consider delete, replace
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        vector<int> cnt(128, 0);
        if (s.size() < t.size()) {
            return isOneEditDistance(t, s);
        }
        int i = 0, j = 0, op = 0;
        while (i <= s.size() && j <= t.size()) {
            if (i == s.size() && j == t.size()) {
                break;
            }
            if (j == s.size() || s[i] != t[j]) {
                if (op) {
                    return false;
                }
                op = 1;
                if (s.size() == t.size()) {
                    ++j;
                }
                ++i;
            } else {
                ++i, ++j;
            }
        }
        return op == 1;
    }
};