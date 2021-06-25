//--- Q: 844. Backspace String Compare

//--- method 1: O(1) space
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size()-1, j = T.size()-1;
        while (1) {
            int cnt = 0;
            while (i >= 0 && (!isalpha(S[i]) || cnt)) {
                if (S[i] == '#') {
                    ++cnt;
                } else if (cnt) {
                    --cnt;
                }
                --i;
            }
            cnt = 0;
            while (j >= 0 && (!isalpha(T[j]) || cnt)) {
                if (T[j] == '#') {
                    ++cnt;
                } else if (cnt) {
                    --cnt;
                }
                --j;
            }
            if (i < 0 || j < 0) {
                break;
            }
            if (S[i] != T[j]) {
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
    bool backspaceCompare(string S, string T) {
        string s = "", t = "";
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '#' && s.size())
                s.pop_back();
            else if (S[i] != '#')
                s.push_back(S[i]);
        }
        for (int i = 0; i < T.size(); ++i) {
            if (T[i] == '#' && t.size())
                t.pop_back();
            else if (T[i] != '#')
                t.push_back(T[i]);
        }
        return s == t;
    }
};