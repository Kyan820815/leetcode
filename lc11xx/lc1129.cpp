//--- Q: 1129. Shortest Path with Alternating Colors

//--- method 1: bfs
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n);
        vector<vector<int>> cres(2, vector<int>(n, INT_MAX));
        vector<vector<vector<int>>> rel(2, vector<vector<int>>(n));
        for (auto &edge: redEdges) {
            rel[0][edge[0]].push_back(edge[1]);
        }
        for (auto &edge: blueEdges) {
            rel[1][edge[0]].push_back(edge[1]);
        }
        queue<pair<int,int>> que;
        que.push({0,0});
        que.push({0,1});
        cres[0][0] = cres[1][0] = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                int node = now.first;
                int color = now.second;
                for (auto &next: rel[color][node]) {
                    if (cres[color^1][next] > cres[color][node]+1) {
                        cres[color^1][next] = cres[color][node]+1;
                        que.push({next, color^1});
                    }                        
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int v = min(cres[0][i], cres[1][i]);
            res[i] = v == INT_MAX ? -1 : v;
        }
        return res;
    }
};