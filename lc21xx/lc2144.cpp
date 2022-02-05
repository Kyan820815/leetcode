//--- Q: 2144. Minimum Cost of Buying Candies With Discount

//--- method 1: sort
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size(), res = 0, t = 0;
        for (int i = n-1; i >= 0; --i) {
            if (++t == 3) {
                t = 0;                
            } else {
                res += cost[i];
            }
        }
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size(), res = 0, t = 0;
        vector<int> cnt(101, 0);
        for (auto &c: cost) {
            ++cnt[c];
        }
        for (int i = 100; i >= 1; --i) {
            for (int j = 0; j < cnt[i]; ++j) {
                if (++t == 3) {
                    t = 0;
                } else {
                    res += i;
                }
            }
        }
        return res;
    }
};