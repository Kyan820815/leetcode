//--- Q: 2154. Keep Multiplying Found Values by Two

//--- method 1: check existed
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<bool> exist(1001, false);
        for (auto &num: nums) {
            exist[num] = true;
        }
        while (original <= 1000 && exist[original]) {
            original *= 2;
        }
        return original;
    }
};