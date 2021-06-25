//--- Q: 575. Distribute Candies

//--- method 1: sort then find # of kinds
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int val = INT_MAX, cnt = 0;
        sort(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); ++i)
        {
            if (candies[i] != val)
            {
                val = candies[i];
                ++cnt;
            }
        }
        return ((cnt < candies.size()/2) ? cnt : candies.size()/2);
    }
};