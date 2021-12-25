//--- Q: 0844. Backspace String Compare

//--- method 1: O(1) space
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        while (i >= 0 || j >= 0) {
            int cnt = 0;
            while (i >= 0 && (cnt || s[i] == '#')) {
                if (s[i] == '#') {
                    ++cnt;
                } else {
                    --cnt;
                }
                --i;
            }
            cnt = 0;
            while (j >= 0 && (cnt || t[j] == '#')) {
                if (t[j] == '#') {
                    ++cnt;
                } else {
                    --cnt;
                }
                --j;
            }
            if (i < 0 || j < 0) {
                break;
            }
            if (s[i] != t[j]) {
                return false;
            }
            --i, --j;
        }
        return i < 0 && j < 0;
    }
};

//--- method 2: O(n) space
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ns = "", nt = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                if (ns.size()) {
                    ns.pop_back();
                }
            } else {
                ns += s[i];
            }
        }
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '#') {
                if (nt.size()) {
                    nt.pop_back();
                }
            } else {
                nt += t[i];
            }
        }
        return ns == nt;
    }
};