//--- Q: 0697. Degree of an Array

//--- method 1: one times pass
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        int maxcnt = 1, mindis = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = {1, i, i};
            } else {
                map[nums[i]].back() = i;
                if (++map[nums[i]].front() > maxcnt) {
                    maxcnt = map[nums[i]].front();
                    mindis = map[nums[i]][2] - map[nums[i]][1] + 1;
                } else if (map[nums[i]].front() == maxcnt) {
                    mindis = min(mindis, map[nums[i]][2] - map[nums[i]][1] + 1);
                }
            }
        }
        return mindis;
    }
};