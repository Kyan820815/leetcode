//--- Q: 1063. Number of Valid Subarrays

//--- method 1: increasing stack
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int res = 0;
        vector<int> sk;
        for (auto &num: nums) {
            while (sk.size() && sk.back() > num) {
                sk.pop_back();
            }
            sk.push_back(num);
            res += sk.size();
        }
        return res;
    }
};