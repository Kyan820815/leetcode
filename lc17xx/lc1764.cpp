//--- Q: 1764. Form Array by Concatenating Subarrays of Another Array

//--- method 1: two pointers
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, j = 0;
        while (i < groups.size() && j < nums.size()) {
            int k;
            for (k = 0; k < groups[i].size() && j+k < nums.size(); ++k) {
                if (groups[i][k] != nums[j+k]) {
                    break;
                }
            }
            if (k == groups[i].size()) {
                j += k;
                ++i;
            } else {
                ++j;
            }
        }
        return i == groups.size();
    }
};