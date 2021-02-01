//--- Q: 1550. Three Consecutive Odds

//--- method 1: linear find
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (auto &num: arr) {
            if (num&1) {
                if (++cnt == 3) {
                    return true;
                }
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};