//--- Q: 0851. Loud and Rich 

//--- method 1: bfs
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> rel(n);
        vector<int> res(n), deg(n, 0);
        for (auto &edge: richer) {
            rel[edge[0]].push_back(edge[1]);
            ++deg[edge[1]];
        } 
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            res[i] = i;
            if (!deg[i]) {
                que.push(i);
            }
        }
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &next: rel[now]) {
                    if (!--deg[next]) {
                        que.push(next);
                    }
                    if (quiet[res[now]] < quiet[res[next]]) {
                        res[next] = res[now];
                    }
                }
            }
        }
        return res;
    }
};

//--- method 2: dfs
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> rel(n);
        vector<int> res(n, -1);
        for (auto &edge: richer) {
            rel[edge[1]].push_back(edge[0]);
        } 
        for (int i = 0; i < n; ++i) {
            dfs(i, res, quiet, rel);
        }
        return res;
    }
    int dfs(int now, vector<int> &res, vector<int> &quiet, vector<vector<int>> &rel) {
        if (res[now] != -1) {
            return res[now];
        }
        res[now] = now;
        for (auto &next: rel[now]) {
            if (quiet[res[now]] > quiet[dfs(next, res, quiet, rel)]) {
                res[now] = res[next];
            }
        }
        return res[now];
    }
};