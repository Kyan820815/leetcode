//--- Q: 0638. Shopping Offers

//--- method 1: dfs recursion
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int sum = 0;
        for (int i = 0; i < price.size(); ++i) {
            sum += price[i]*needs[i];
        }
        for (auto &sp: special) {
            auto new_needs = count(needs, sp);
            if (new_needs.size()) {
                sum = min(sum, sp.back()+shoppingOffers(price, special, new_needs));
            }
        }
        return sum;
    }
    vector<int> count(vector<int> &needs, vector<int> &special) {
        vector<int> new_needs = needs;
        for (int i = 0; i < needs.size(); ++i) {
            if (needs[i] < special[i]) {
                return {};
            }
            new_needs[i] -= special[i];
        }
        return new_needs;
    }
};