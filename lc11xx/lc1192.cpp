//--- Q: 1192. Critical Connections in a Network

//--- method 1: rank traversal
class Solution {
public:
    vector<vector<int>> rel, res;
    vector<int> visit;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        rel.resize(n);
        visit.resize(n, -1);
        for (auto &connection: connections) {
            rel[connection[0]].push_back(connection[1]);
            rel[connection[1]].push_back(connection[0]);
        }
        dfs(0, 0, -1);
        return res;
    }
    int dfs(int now, int rank, int parent) {
        int min_rank = rank;
        visit[now] = rank;
        for (auto &next: rel[now]) {
            if (next == parent) {
                continue;
            }
            if (visit[next] != -1) {
                min_rank = min(min_rank, visit[next]);
            } else {
                int rtn_rank = dfs(next, rank+1, now);
                if (rank < rtn_rank) {
                    res.push_back({now,next});
                } else {
                    min_rank = min(min_rank, rtn_rank);
                }
            }
        }
        return visit[now] = min_rank;
    }
};