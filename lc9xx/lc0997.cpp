//--- Q: 997. Find the Town Judge

//--- method 1: directed graph
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> deg(N+1, 0);
        for (int i = 0; i < trust.size(); ++i) {
            ++deg[trust[i][1]];
            --deg[trust[i][0]];
        }
        for (int i = 1; i <= N; ++i)
            if (deg[i] == N-1)
                return i;
        return -1;
    }
};