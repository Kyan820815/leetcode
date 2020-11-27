//--- Q: 1464. Maximum Product of Two Elements in an Array

//--- method 1: linear find
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int *a, *b;
        a = b = NULL;
        for (int i = 0; i < nums.size(); ++i) {
            if (!a || *a <= nums[i]) {
                b = a;
                a = &nums[i];
            } else if (!b || *b <= nums[i]) {
                b = &nums[i];
            }
        }
        return (*a-1) * (*b-1);
    }
};