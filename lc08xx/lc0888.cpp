//--- Q: 0888. Fair Candy Swap

//--- method 1: unordered_set, find pair
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        unordered_set<int> bset;
        int suma = 0, sumb = 0;
        for (auto &v: aliceSizes) {
            suma += v;
        }
        for (auto &v: bobSizes) {
            sumb += v;
            bset.insert(v);
        }
        int diff = (suma-sumb)/2;
        for (auto &v: aliceSizes) {
            if (bset.find(v-diff) != bset.end()) {
                return {v, v-diff};
            }
        }
        return {-1,-1};
    }
};