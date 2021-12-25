//--- Q: 0821. Shortest Distance to a Character

//---method 1: count distance by difference
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), lastloc = -n;
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                lastloc = i;
            } else {
                res[i] = i-lastloc;
            }
        }
        for (int i = lastloc-1; i >= 0; --i) {
            if (s[i] == c) {
                lastloc = i;
            } else {
                res[i] = min(res[i], lastloc-i);
            }
        }
        return res;
    }
};

//--- method 2: count distance by addition
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, 0);
        for (int i = 0, cnt = n; i < n; ++i, ++cnt) {
            if (s[i] == c) {
                cnt = 0;
            } else {
                res[i] = cnt;
            }
        }
        for (int i = n-1, cnt = n; i >= 0; --i, ++cnt) {
            if (s[i] == c) {
                cnt = 0;
            } else {
                res[i] = min(res[i], cnt);
            }
        }
        return res;
    }
};