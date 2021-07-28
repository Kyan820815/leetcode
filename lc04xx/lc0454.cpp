//--- Q: 0454. 4Sum II

//--- method 1: O(n^2) hashmap
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        int res = 0;
        for (auto &num1: nums1) {
            for (auto &num2: nums2) {
                ++map[num1+num2];
            }
        }
        for (auto &num3: nums3) {
            for (auto &num4: nums4) {
                res += map[-num3-num4];
            }
        }
        return res;
    }
};