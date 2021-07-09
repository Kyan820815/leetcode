//--- Q: 0207. Course Schedule

//--- method 1: bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> rel(n);
        vector<int> deg(n, 0);
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
                for (auto &next: rel[now]) {
                    if (!--deg[next]) {
                        que.push(next);
                    }
                }
            }
        }
        return !n;
    }
};

//--- method 2: dfs with visit state
class Solution {
public:
    int n;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        vector<vector<int>> rel(n);
        vector<int> visit(n, -1);
        for (auto &courses: prerequisites) {
            rel[courses[1]].push_back(courses[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (visit[i] == -1) {
                if (!dfs(i, visit, rel)) {
                    return false;
                }
            }
        }
        return true;
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
        return visit[now] = 1;
    }
};

//--- method 3: dfs with degree
class Solution {
public:
    int n;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        vector<vector<int>> rel(n);
        vector<int> deg(n, 0);
        for (auto &courses: prerequisites) {
            rel[courses[1]].push_back(courses[0]);
            ++deg[courses[0]];
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!deg[i]) {
                dfs(i, deg, rel);
            }
        }
        return !n;
    }
    void dfs(int now, vector<int> &deg, vector<vector<int>> &rel) {
        --n;
        for (auto &next: rel[now]) {
            if (!--deg[next]) {
                deg[next] = -1;
                dfs(next, deg, rel);
            }
        }
    }
};