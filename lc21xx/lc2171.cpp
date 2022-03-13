//--- Q: 2171. Removing Minimum Number of Magic Beans

//--- method 1: greedy, use each nubmer as final bean
class Solution {
public:
    using ll = long long;
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        ll tsum = 0;
        vector<int> cnt(100001, 0);
        for (auto &bean: beans) {
            ++cnt[bean];
            tsum += bean;
        }
        ll res = LONG_MAX, cur = 0;
        for (int i = 1; i <= 100000; ++i) {
            if (!cnt[i]) {
                continue;
            }
            res = min(res, tsum-(ll)n*i);
            n -= cnt[i];
        }
        return res;
    }
};