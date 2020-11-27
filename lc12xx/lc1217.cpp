//--- Q: 1217. Play with Chips

//--- method 1:
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0;
        for (int i = 0; i < chips.size(); ++i) {
            if (chips[i]&1) {
                ++odd;
            }
        }
        return min((int)chips.size()-odd, odd);
    }
};