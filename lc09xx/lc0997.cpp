//--- Q: 0997. Find the Town Judge

//--- method 1: directed graph
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> deg(n, 0);
        for (auto &pair: trust) {
            --deg[pair[0]-1];
            ++deg[pair[1]-1];
        }
        for (int i = 0; i < n; ++i) {
            if (deg[i] == n-1) {
                return i+1;
            }
        }
        return -1;
    }
};