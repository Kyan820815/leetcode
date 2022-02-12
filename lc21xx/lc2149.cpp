//--- Q: 2149. Rearrange Array Elements by Sign

//--- method 1: two pointers
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0, j = 0; i < n || j < n; ++i, ++j) {
            while (i < n && nums[i] < 0) {
                ++i;
            }
            if (i < n) {
                res.push_back(nums[i]);
            }
            while (j < n && nums[j] > 0) {
                ++j;
            }
            if (j < n) {
                res.push_back(nums[j]);
            }
        }
        return res;
    }
};