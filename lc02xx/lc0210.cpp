//--- Q: 0210. Course Schedule II

//--- method 1: bfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> rel(n);
        vector<int> deg(n, 0), res;
        for (auto &courses: prerequisites) {
            rel[courses[1]].push_back(courses[0]);
            ++deg[courses[0]];
        }
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
                res.push_back(now);
                for (auto &next: rel[now]) {
                    if (!--deg[next]) {
                        que.push(next);
                    }
                }
            }
        }
        return !n ? res : vector<int>{};
    }
};

//--- method 2: dfs
class Solution {
public:
    int n;
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        vector<vector<int>> rel(n);
        vector<int> visit(n, -1);
        for (auto &courses: prerequisites) {
            rel[courses[1]].push_back(courses[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (visit[i] == -1) {
                if (!dfs(i, visit, rel)) {
                    return vector<int>{};
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool dfs(int now, vector<int> &visit, vector<vector<int>> &rel) {
        if (visit[now] != -1) {
            return visit[now];
        }
        visit[now] = 0;
        for (auto &next: rel[now]) {
            if (!dfs(next, visit, rel)) {
                return visit[now];
            }
        }
        res.push_back(now);
        return visit[now] = 1;
    }
};