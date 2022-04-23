//--- Q: 1519. Number of Nodes in the Sub-Tree With the Same Label

//--- method 1: dfs
class Solution {
public:
    vector<int> res;
    vector<vector<int>> rel;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        rel.resize(n);
        res.resize(n, 0);
        for (auto &edge: edges) {
            rel[edge[0]].push_back(edge[1]);
            rel[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, labels);
        return res;
    }
    vector<int> dfs(int now, int p, string &labels) {
        vector<int> cnt(26, 0);
        for (auto &child: rel[now]) {
            if (p == child) {
                continue;
            }
            auto tmp = dfs(child, now, labels);
            for (int i = 0; i < 26; ++i) {
                cnt[i] += tmp[i];
            }
        }
        res[now] = ++cnt[labels[now]-'a'];
        return cnt;
    }
};