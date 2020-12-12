//--- Q: 1466. Reorder Routes to Make All Paths Lead to the City Zero

//--- method 1: bfs
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> rel(n);
        for (int i = 0; i < connections.size(); ++i) {
            rel[connections[i][0]].push_back({connections[i][1], 1});
            rel[connections[i][1]].push_back({connections[i][0], 0});
        }
        queue<int> que;
        vector<int> visit(n);
        que.push(0);
        visit[0] = 1;
        int res = 0;
        while (que.size()) {
            int qsize = 1;
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                for (int j = 0; j < rel[now].size(); ++j) {
                    if (!visit[rel[now][j].first]) {
                        visit[rel[now][j].first] = 1;
                        if (rel[now][j].second) {
                            ++res;
                        }
                        que.push(rel[now][j].first);
                    }
                }
            }
        }
        return res;
    }
};