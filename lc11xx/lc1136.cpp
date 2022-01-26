//--- Q: 1136. Parallel Courses

//--- method 1: bfs
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> rel(n);
        vector<int> deg(n, 0);
        for (auto &relation: relations) {
            rel[relation[0]-1].push_back(relation[1]-1);
            ++deg[relation[1]-1];
        }
        int res = 0;
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                que.push(i);
            }
        }
        while (que.size()) {
            auto qsize = que.size();
            n -= qsize;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &next: rel[now]) {
                    if (!--deg[next]) {
                        que.push(next);
                    }
                }
            }
            ++res;
        }
        return !n ? res : -1;
    }
};