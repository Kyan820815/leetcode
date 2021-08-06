//--- Q: 624. Maximum Distance in Arrays

//--- method 1: find min max value
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, minv = 10000, maxv = -10000;
        for (auto &array: arrays) {
            res = max(res, max(array.back()-minv, maxv-array.front()));
            minv = min(minv, array.front());
            maxv = max(maxv, array.back());
        }
        return res;
    }
};