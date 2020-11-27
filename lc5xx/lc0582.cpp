//--- Q: 582. Kill Process

//--- method 1: dfs with recursion
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        unordered_map<int, vector<int>> child;
        vector<int> res = {kill};
        for (int i = 0; i < n; ++i) {
            child[ppid[i]].push_back(pid[i]);
        }
        dfs(kill, child, res);
        return res;
    }
    void dfs(int now, unordered_map<int, vector<int>> &child, vector<int> &res) {
        for (int i = 0; i < child[now].size(); ++i) {
            res.push_back(child[now][i]);
            if (child[child[now][i]].size()) {
                dfs(child[now][i], child, res);
            }
        }
    }
};

//--- method 2: bfs with queue
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        unordered_map<int, vector<int>> child;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            child[ppid[i]].push_back(pid[i]);
        }
        queue<int> que{{kill}};
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                res.push_back(now);
                for (int j = 0; j < child[now].size(); ++j) {
                    que.push(child[now][j]);
                }
            }
        }
        return res;
    }
};