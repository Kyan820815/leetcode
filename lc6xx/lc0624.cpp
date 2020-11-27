//--- Q: 624. Maximum Distance in Arrays

//--- method 1: find min max value
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = INT_MIN, minv = 10000, maxv = -10000;
        for (int i = 0; i < arrays.size(); ++i) {
            res = max(res, max(arrays[i].back() - minv, maxv - arrays[i][0]));
            minv = min(minv, arrays[i][0]);
            maxv = max(maxv, arrays[i].back());
        }
        return res;
    }
};