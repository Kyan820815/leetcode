//--- Q: 2027. Minimum Moves to Convert String

//--- method 1:
class Solution {
public:
    int minimumMoves(string s) {
        vector<int> cnt;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'X') {
                cnt.push_back(i);
            }
        }
        if (!cnt.size()) {
            return res;
        } else {
            int times = 1, start = 0;
            for (int i = 1; i < cnt.size(); ++i) {
                if (cnt[i]-cnt[start] > 2) {
                    ++res;
                    times = 1, start = i;
                } else {
                    if (++times == 3) {
                        start = i+1;
                        times = start < cnt.size();
                        ++res, ++i;
                    }
                }
            }
            return res + (times!=0);
        }
    }
};

//--- method 2: greedy
class Solution {
public:
    int minimumMoves(string s) {
        int res = 0, i = 0, n = s.size();
        while (i < n) {
            if (s[i] == 'O') {
                ++i;
            } else {
                ++res;
                i += 3;
            }
        }
        return res;
    }
};