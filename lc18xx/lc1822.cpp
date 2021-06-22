//--- Q: 1822. Sign of the Product of an Array

//--- method 1:
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for (auto &num: nums) {
            if (num < 0) {
                ++neg;
            } else if (!num) {
                return 0;
            }
        }
        return neg&1 ? -1 : 1;
    }
};