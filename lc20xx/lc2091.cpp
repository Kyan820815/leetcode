//--- Q: 2091. Removing Minimum and Maximum From Array

//--- method 1: three cases by find max and min index
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxidx = max_element(nums.begin(), nums.end())-nums.begin();
        int minidx = min_element(nums.begin(), nums.end())-nums.begin();
        if (minidx > maxidx) {
            swap(minidx, maxidx);
        }
        int d1 = minidx+1, d2 = maxidx-minidx, d3 = n-maxidx;
        return min({d1+d2, d2+d3, d1+d3});
    }
};