//--- Q: 785. Is Graph Bipartite?

//--- method 1: bfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visit(n, -1);
        queue<int> que;
        for (int i = 0; i < graph.size(); ++i) {
            if (visit[i] == -1) {
                que.push(i);
                visit[i] = 0;
                while (que.size()) {
                    int qsize = que.size();
                    for (int j = 0; j < qsize; ++j) {
                        auto now = que.front();
                        que.pop();
                        for (int k = 0; k < graph[now].size(); ++k) {
                            if (visit[graph[now][k]] == -1) {
                                visit[graph[now][k]] = visit[now] ^ 1;
                                que.push(graph[now][k]);
                            } else if (visit[graph[now][k]] == visit[now]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};