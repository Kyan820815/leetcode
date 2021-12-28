//--- Q: 0908. Smallest Range I

//--- method 1: find max and min
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minv = INT_MAX, maxv = INT_MIN;
        for (auto &num: nums) {
            minv = min(minv, num);
            maxv = max(maxv, num);
        }
        return maxv-minv > 2*k ? maxv-minv-2*k : 0;
    }
};