//--- Q: 0525. Contiguous Array

//--- method 1: accumulative sum. O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        map[0] = -1;
        int val = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            val += nums[i] == 1 ? 1 : -1;
            if (map.find(val) == map.end()) {
                map[val] = i;
            } else {
                res = max(res, i-map[val]);
            }
        }
        return res;
    }
};