//--- Q: 0598. Range Addition II

//--- method 1: find min row & column in every operations
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto &op: ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m*n;
    }
};