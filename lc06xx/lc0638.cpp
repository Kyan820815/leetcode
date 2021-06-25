//--- Q: 638. Shopping Offers

//--- method 1: dfs recursion
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0;
        for (int i = 0; i < needs.size(); ++i) {
            res += needs[i] * price[i];
        }
        for (int i = 0; i < special.size(); ++i) {
            vector<int> remain = sub(special[i], needs);
            if (!remain.size()) {
                continue;
            }
            res = min(res, special[i].back() + shoppingOffers(price, special, remain));
        }
        return res;
    }
    vector<int> sub(vector<int> &special, vector<int> &needed) {
        vector<int> r(needed.size(), 0);
        for (int i = 0; i < r.size(); ++i) {
            if (needed[i]-special[i] < 0) {
                return vector<int>();
            }
            r[i] = needed[i] - special[i];
        }
        return r;
    }
};