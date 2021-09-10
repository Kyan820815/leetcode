//--- Q: 0797. All Paths From Source to Target

//--- method 1: dfs recursion
class Solution {
public:
    vector<int> res;
    vector<vector<int>> res_vec;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, graph);
        return res_vec;
    }
    void dfs(int now, vector<vector<int>>& graph) {
        res.push_back(now);
        if (now == graph.size()-1) {
            res_vec.push_back(res);
            res.pop_back();
            return;
        }
        for (auto &next: graph[now]) {
            dfs(next, graph);
        }
        res.pop_back();
    }
};

//--- method 2: bfs
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<pair<int, vector<int>>> que;
        que.push({0, {0}});
        vector<vector<int>> res_vec;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (now.first == graph.size()-1) {
                    res_vec.push_back(now.second);
                } else {
                    for (auto &next: graph[now.first]) {
                        auto nvec = now.second;
                        nvec.push_back(next);
                        que.push({next, nvec});
                    }
                }
            }
        }
        return res_vec;
    }
};
