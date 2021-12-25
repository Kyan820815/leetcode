//--- Q: 0886. Possible Bipartition

//--- method 1: bfs
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> visit(n, -1);
        vector<vector<int>> rel(n);
        for (auto &dislike: dislikes) {
            rel[dislike[0]-1].push_back(dislike[1]-1);
            rel[dislike[1]-1].push_back(dislike[0]-1);
        }
        for (int i = 0; i < n; ++i) {
            if (visit[i] == -1) {
                queue<int> que;
                que.push(i);
                while (que.size()) {
                    auto qsize = que.size();
                    while (qsize--) {
                        auto now = que.front();
                        que.pop();
                        for (auto &next: rel[now]) {
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> rel(n);
        parent.resize(n, -1);
        for (auto &dislike: dislikes) {
            rel[dislike[0]-1].push_back(dislike[1]-1);
            rel[dislike[1]-1].push_back(dislike[0]-1);
        }
        for (auto &group: rel) {
            if (!group.size()) {
                continue;
            }
            int ap = findp(group[0]);
            for (int i = 1; i < group.size(); ++i) {
                int bp = findp(group[1]);
                if (ap != bp) {
                    parent[ap] = bp;
                }
                ap = findp(group[0]);
            }
        }
        for (int i = 0; i < n; ++i) {
              if (!rel[i].size()) {
                continue;
            }
            int ap = findp(i);
            for (auto &next: rel[i]) {
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