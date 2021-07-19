//--- Q: 0356. Line Reflection

//--- method 1: O(n) find max and min of x
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int minv = INT_MAX, maxv = INT_MIN;
        unordered_set<string> set;
        for (auto pt: points) {
            minv = min(minv, pt[0]);
            maxv = max(maxv, pt[0]);
            set.insert(to_string(pt[0])+","+to_string(pt[1]));
        }
        int mid = maxv+minv;
        for (auto &pt: points) {
            auto sym_pt = to_string(mid-pt[0])+","+to_string(pt[1]);
            if (set.find(sym_pt) == set.end()) {
                return false;
            }
        }
        return true;
    }
};