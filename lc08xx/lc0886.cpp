//--- Q: 886. Possible Bipartition

//--- method 1: bfs
class Solution {
public:
    vector<int> parentl;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> rel(n);
        for (auto &dislike: dislikes) {
            rel[dislike[0]-1].push_back(dislike[1]-1);
            rel[dislike[1]-1].push_back(dislike[0]-1);
        }
        queue<pair<int, int>> que;
        vector<int> visit(n, -1);
        for (int i = 0; i < n; ++i) {
            if (visit[i] == -1) {
                visit[i] = 0;
                que.push({i, 0});
                while (que.size()) {
                    int qsize = que.size();
                    for (int j = 0; j < qsize; ++j) {
                        auto now = que.front();
                        que.pop();
                        for (auto &pt: rel[now.first]) {
                            if (visit[pt] == -1) {
                                visit[pt] = now.second^1;
                                que.push({pt, visit[pt]});
                            } else if (visit[pt] == now.second) {
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