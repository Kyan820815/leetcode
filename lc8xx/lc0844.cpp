//--- Q: 844. Backspace String Compare

//--- method 1: O(1) space
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sidx = S.size()-1, tidx = T.size()-1;
        while (1) {
            int sj = 0, tj = 0;
            while (sidx >= 0 && (sj || S[sidx] == '#')) {
                if (S[sidx] == '#')
                    ++sj;
                else
                    --sj;
                --sidx;
            }
            while (tidx >= 0 && (tj || T[tidx] == '#')) {
                if (T[tidx] == '#')
                    ++tj;
                else
                    --tj;
                --tidx;
            }
            if (sidx >= 0 && tidx >= 0 && S[sidx] == T[tidx]) {
                --sidx;
                --tidx;
            } else
                break;
        }
        return sidx == -1 && tidx == -1;
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