//--- Q: 1376. Time Needed to Inform All Employees

//--- method 1: bfs
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> rel(n);
        int start, res = 0;
        for (int i = 0; i < manager.size(); ++i) {
            if (i != headID) {
                rel[manager[i]].push_back(i);
            }
        }
        queue<int> que;
        que.push(headID);
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                res = max(res, informTime[now]);
                for (auto &next: rel[now]) {
                    informTime[next] += informTime[now];
                    que.push(next);
                }
            }
        }
        return res;
    }
};

//--- method 2:  dfs
class Solution {
public:
    vector<vector<int>> rel;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        rel.resize(n);
        int start, res = 0;
        for (int i = 0; i < manager.size(); ++i) {
            if (i != headID) {
                rel[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }
    int dfs(int now, vector<int> &informTime) {
        int maxv = 0;
        for (auto &next: rel[now]) {
            maxv = max(maxv, dfs(next, informTime)+informTime[now]);
        }
        return maxv;
    }
};