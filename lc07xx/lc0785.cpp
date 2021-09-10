//--- Q: 0785. Is Graph Bipartite?

//--- method 1: bfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visit(n, -1);
        for (int i = 0; i < n; ++i) {
            if (visit[i] == -1) {
                queue<int> que;
                visit[i] = 0;
                que.push(i);
                while (que.size()) {
                    auto qsize = que.size();
                    while (qsize--) {
                        auto now = que.front();
                        que.pop();
                        for (auto &next: graph[now]) {
                            if (visit[next] == -1) {
                                visit[next] = visit[now]^1;
                                que.push(next);
                            } else if (visit[next] == visit[now]) {
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

//--- method 2: union find
class Solution {
public:
    vector<int> parent;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        parent.resize(n,-1);
        for (auto &group: graph) {
            if (!group.size()) {
                continue;
            }
            int ap = findp(group[0]);
            for (int i = 1; i < group.size(); ++i) {
                int bp = findp(group[i]);
                if (ap != bp) {
                    parent[ap] = bp;
                }
                ap = findp(group[0]);
            }
        }
        for (int i = 0; i < graph.size(); ++i) {
            if (!graph[i].size()) {
                continue;
            }
            int ap = findp(i);
            for (auto &next: graph[i]) {
                int bp = findp(next);
                if (ap == bp) {
                    return false;
                }
            }
        }
        return true;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};