//--- Q: 1798. Maximum Number of Consecutive Values You Can Make

//--- method 1: greedy
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int val = 0;
        for (auto &coin: coins) {
            if (val+1 < coin) {
                break;
            }
            val += coin;
        }
        return val+1;
    }
};