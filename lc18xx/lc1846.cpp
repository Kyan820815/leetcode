//--- Q: 1846. Maximum Element After Decreasing and Rearranging

//--- method 1: greedy
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int res = 0;
        for (auto &val: arr) {
            res = min(res+1, val);
        }
        return res;
    }
};