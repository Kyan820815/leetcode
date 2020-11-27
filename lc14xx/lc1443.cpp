//--- Q: 1443. Minimum Time to Collect All Apples in a Tree

//--- method 1: dfs
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> rel(n);
        for (int i = 0; i < edges.size(); ++i) {
            rel[edges[i][0]].push_back(edges[i][1]);
            rel[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(-1, 0, rel, hasApple);
    }
    int dfs(int parent, int now, vector<vector<int>> &rel, vector<bool>& hasApple) {
        int val = 0;
        for (int i = 0; i < rel[now].size(); ++i) {
            if (rel[now][i] == parent) {
                continue;
            }
            val += dfs(now, rel[now][i], rel, hasApple);
        }
        if (hasApple[now] || val) {
			// make sure current node is not root.
            if (parent != -1) {
                val += 2;
            }
        }
        return val;
    }
};
