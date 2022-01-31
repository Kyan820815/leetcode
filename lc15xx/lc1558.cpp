//--- Q: 1558. Minimum Numbers of Function Calls to Make Target Array

//--- method 1: count odd and even operations
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int odd = 0, even = 0;
        for (auto &num: nums) {
            int ceven = 0;
            while (num) {
                if (num&1) {
                    --num;
                    ++odd;
                } else {
                    num >>= 1;
                    ++ceven;
                }
            }
            even = max(even, ceven);
        }
        return odd+even;
    }
};