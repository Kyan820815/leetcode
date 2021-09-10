//--- Q: 0747. Largest Number At Least Twice of Others

//--- method 1: linear processing
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = -1, second = -1, fi, si;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= first) {
                second = first, first = nums[i];
                si = fi, fi = i;
            } else if (nums[i] > second) {
                second = nums[i];
                si = i;
            }
        }
        return first >= second*2 ? fi : -1;
    }
};