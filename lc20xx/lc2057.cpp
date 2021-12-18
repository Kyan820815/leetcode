//--- Q: 2057. Smallest Index With Equal Value

//--- method 1: index accumulation
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int idx = 0;
        for (int i = 0 ; i < nums.size(); ++i) {
            if (idx == nums[i]) {
                return i;
            }
            if (++idx == 10) {
                idx = 0;
            }
        }
        return -1;
    }
};