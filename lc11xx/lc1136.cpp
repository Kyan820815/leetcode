//--- Q: 1136. Parallel Courses

//--- method 1: bfs
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> rel(n);
        vector<int> deg(n);
        for (auto &relation: relations) {
            rel[relation[0]-1].push_back(relation[1]-1);
            ++deg[relation[1]-1];
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                que.push(i);
            }
        }
        int level = 0;
        while (que.size()) {
            auto qsize = que.size();
            n -= qsize;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &node: rel[now]) {
                    if (!--deg[node]) {
                        que.push(node);
                    }
                }
            }
            ++level;
        }
        return !n ? level : -1;
    }
};