//--- Q: 0914. X of a Kind in a Deck of Cards

//--- method 1: find greatest divisor
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> cnt(10000, 0);
        for (auto &val: deck) {
            ++cnt[val];
        }
        int res = 0;
        for (int i = 0; i < 10000; ++i) {
            if (!cnt[i]) {
                continue;
            }
            int a = cnt[i], b = res;
            while (a && b) {
                a %= b;
                swap(a, b);
            }
            res = a;
            if (res == 1) {
                break;
            }
        }
        return res > 1;
    }
};