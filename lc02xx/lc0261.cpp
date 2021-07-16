//--- Q: 0261. Graph Valid Tree

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n, -1);
        for (auto &edge: edges) {
            int ap = findp(edge[0]);
            int bp = findp(edge[1]);
            if (ap != bp) {
                --n;
                parent[ap] = bp;
            } else {
                return false;
            }
        }
        return n == 1;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};

//--- method 2: bfs with queue
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> rel(n);
        vector<int> deg(n, 0);
        for (auto &edge: edges) {
            rel[edge[0]].push_back(edge[1]);
            rel[edge[1]].push_back(edge[0]);
            ++deg[edge[0]];
            ++deg[edge[1]];
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                que.push(i);
            }
        }
        int cnt = n;
        while (que.size()) {
            auto qsize = que.size();
            cnt -= qsize;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &next: rel[now]) {
                    if (--deg[next] == 1) {
                        que.push(next);
                    }
                }
            }
        }
        return cnt <= 1 && edges.size() == n-1;
    }
};

//--- method 3: dfs recursion
class Solution {
public:
    vector<vector<int>> rel;
    vector<int> visit;
    bool validTree(int n, vector<vector<int>>& edges) {
        rel.resize(n);
        visit.resize(n, -1);
        for (auto &edge: edges) {
            rel[edge[0]].push_back(edge[1]);
            rel[edge[1]].push_back(edge[0]);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (visit[i] == -1) {
                if (!dfs(i, -1)) {
                    return false;
                }
                ++cnt;
            }
        }
        return cnt <= 1;
    }
    int dfs(int now, int p) {
        if (visit[now] != -1) {
            return visit[now];
        }
        visit[now] = 0;
        for (auto &next: rel[now]) {
            if (next == p) {
                continue;
            }
            if (!dfs(next, now)) {
                return visit[now];
            }
        }
        return visit[now] = 1;
    }
};