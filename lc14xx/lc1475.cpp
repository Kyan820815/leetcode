//--- Q: 1475. Final Prices With a Special Discount in a Shop

//--- method 1: stack iteration
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> sk;
        for (int i = 0; i < prices.size(); ++i) {
            while (sk.size() && prices[i] <= prices[sk.back()]) {
                prices[sk.back()] -= prices[i];
                sk.pop_back();
            }
            sk.push_back(i);
        }
        return prices;
    }
};
