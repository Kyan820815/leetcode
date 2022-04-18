//--- Q: 1405. Longest Happy String

//--- method 1: sort
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        vector<int> idx = {0,1,2}, val = {a,b,c};
        sort(idx.begin(), idx.end(), [&val](const int &a, const int &b) {
            return val[a] > val[b];
        });
        while (val[idx[0]]) {
            vector<int> cnt(2, 0);
            cnt[0] = res.size() && res.back() == 'a'+idx[0] ? 1 : 2;
			cnt[1] = 1;
            for (int i = 0; i < 2; ++i) {
                cnt[i] = min(cnt[i], val[idx[i]]);
                val[idx[i]] -= cnt[i];
                res += string(cnt[i], 'a'+idx[i]);
            }
            if (!cnt[1]) {
                break;
            }
            sort(idx.begin(), idx.end(), [&val](const int &a, const int &b) {
                return val[a] > val[b];
            });
        }
        return res;
    }
};

//--- method 2: recursion
class Solution {
public:
    string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
        if (c > b) {
            return longestDiverseString(a, c, b, aa, cc, bb);
        }
        if (b > a) {
            return longestDiverseString(b, a, c, bb, aa, cc);
        }
        if (!b) {
            return string(min(a,2), aa);
        }
        int used_a = min(2, a), used_b = a-used_a >= b ? 1 : 0;
        return string(used_a, aa) + string(used_b, bb) + longestDiverseString(a-used_a, b-used_b, c, aa, bb, cc);
    }
};
