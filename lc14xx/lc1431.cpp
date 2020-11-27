//--- Q: 1431. Kids With the Greatest Number of Candies
 
//--- method 1: O(n) time
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(), maxv = 0;
        vector<bool> res(n);
        for (int i = 0; i < n; ++i) {
            maxv = max(maxv, candies[i]);
        }
        for (int i = 0; i < n; ++i) {
            res[i] = candies[i] + extraCandies >= maxv;
        }
        return res;
    }
};