//--- Q: 0582. Kill Process

//--- method 1: bfs with queue
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> rel;
        for (int i = 0; i < ppid.size(); ++i) {
            rel[ppid[i]].push_back(pid[i]);
        }
        queue<int> que;
        vector<int> res;
        que.push(kill);
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                res.push_back(now);
                for (auto &next: rel[now]) {
                    que.push(next);
                }
            }
        }
        return res;
    }
};

//--- method 2: dfs with recursion
class Solution {
public:
    vector<int> res;
    unordered_map<int, vector<int>> rel;
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        for (int i = 0; i < ppid.size(); ++i) {
            rel[ppid[i]].push_back(pid[i]);
        }
        dfs(kill);
        return res;
    }
    void dfs(int now) {
        res.push_back(now);
        for (auto &next: rel[now]) {
            dfs(next);
        }
    }
};