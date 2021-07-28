//--- Q: 0401. Binary Watch

//--- method 1: recursion
class Solution {
public:
    vector<string> res;
    vector<int> opts = {1,2,4,8,1,2,4,8,16,32};
    vector<string> readBinaryWatch(int turnedOn) {
        dfs(0, 0, 0, turnedOn);
        return res;
    }
    void dfs(int idx, int h, int m, int k) {
        if (!k) {
            if (h < 12 && m < 60) {
                res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
            return;
        }
        for (int i = idx; i < opts.size(); ++i) {
            if (i < 4) {
                dfs(i+1, h+opts[i], m, k-1);
            } else {
                dfs(i+1, h, m+opts[i], k-1);
            }
        }
    }
};

//--- method 2: bit manipulation
class Solution {
public:
    vector<string> res;
    vector<string> readBinaryWatch(int turnedOn) {
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (countbits(i)+countbits(j) == turnedOn) {
                    res.push_back(to_string(i)+":"+(j<10 ?"0":"")+to_string(j));
                }
            }
        }
        return res;
    }
    int countbits(int num) {
        int bits = 0;
        while (num) {
            bits += (num&1);
            num >>= 1;
        }
        return bits;
    }
};