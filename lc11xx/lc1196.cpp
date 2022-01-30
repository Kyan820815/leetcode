//--- Q: 1196. How Many Apples Can You Put into the Basket

//--- method 1: bucket sort
class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        vector<int> cnt(1001, 0);
        for (auto &w: weight) {
            ++cnt[w];
        }
        int budget = 5000, res = 0;
        for (int i = 1; i <= 1000 && budget-i >= 0; ++i) {
            for (int j = 0; j < cnt[i] && budget-i >= 0; ++j) {
                ++res;
                budget -= i;
            }
        }
        return res;
    }
};

//--- method 2: nlogn sort
class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int budget = 5000, res = 0;
        for (int i = 0; i < weight.size() && budget >= weight[i]; ++i) {
            budget -= weight[i];
            ++res;
        }
        return res;
    }
};