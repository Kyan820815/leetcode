//--- Q: 0860. Lemonade Change

//--- method 1: one pass count # of 5 and 10
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto &bill: bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10) {
                if (--five < 0) {
                    return false;
                }
                ++ten;
            } else {
                if (ten && five) {
                    --ten, --five;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};