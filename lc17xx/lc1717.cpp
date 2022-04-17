//--- Q: 1717. Maximum Score From Removing Substrings

//--- method 1: greedy and stack, O(n) space
class Solution {
public:
    int res = 0;
    int maximumGain(string s, int x, int y) {
        string fstr = "ab", sstr = "ba";
        if (x < y) {
            swap(x, y);
            swap(fstr, sstr);
        }
        string sk1 = "", sk2 = "";
        process(s, sk1, fstr, x);
        process(sk1, sk2, sstr, y);
        return res;
    }
    void process(string &s, string &sk, string &sub, int score) {
        for (auto &ch: s) {
            if (sk.size() && sk.back() == sub[0] && ch == sub[1]) {
                sk.pop_back();
                res += score;
            } else {
                sk += ch;
            }
        }
    }
};

//--- method 2: greedy and stack, O(1) space
class Solution {
public:
    int res = 0;
    int maximumGain(string s, int x, int y) {
        string fstr = "ab", sstr = "ba";
        if (x < y) {
            swap(x, y);
            swap(fstr, sstr);
        }
        int idx1 = 0, idx2 = 0;
        process(s, idx1, s.size(), fstr, x);
        process(s, idx2, idx1, sstr, y);
        return res;
    }
    void process(string &s, int &idx, int n, string &sub, int score) {
        for (int i = 0; i < n; ++i) {
            if (idx > 0 && s[idx-1] == sub[0] && s[i] == sub[1]) {
                --idx;
                res += score;
            } else {
                swap(s[idx++], s[i]);
            }
        }
    }
};