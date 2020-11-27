//--- Q: 1192. Critical Connections in a Network

//--- method 1: rank traversal
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> rank(n, -2);
        vector<vector<int>> relation(n), res;
        for (int i = 0; i < connections.size(); ++i) {
            relation[connections[i][0]].push_back(connections[i][1]);
            relation[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(-1, 0, rank, relation, res);
        return res;
    }
    int dfs(int lr, int now, vector<int> &rank, vector<vector<int>> &relation, vector<vector<int>> &res) {
        rank[now] = lr + 1;
        int min_rank = rank[now];
        for (int i = 0; i < relation[now].size(); ++i) {
			// if this node is parent, skip
            if (rank[relation[now][i]] == lr)
                continue;
			// if not visited
            if (rank[relation[now][i]] == -2) {
                int cur_min_rank = dfs(rank[now], relation[now][i], rank, relation, res);
				// this edge should be added since there is no cycle 
                if (cur_min_rank > rank[now]) {
                    res.push_back({now, relation[now][i]});
                } else {
                    min_rank = min(min_rank, cur_min_rank);
                }
            } else {
				// this node was visited before, cycle happens
                min_rank = min(min_rank, rank[relation[now][i]]);
            }
        }
        return min_rank;
    }
};

//--- method 1-2: my version
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> rank(n, -1);
        vector<vector<int>> rel(n);
        for (int i = 0; i < connections.size(); ++i) {
            rel[connections[i][0]].push_back(connections[i][1]);
            rel[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(0, 0, -1, rel, rank);
        return res;
    }
    int dfs(int val, int now, int p, vector<vector<int>> &rel, vector<int> &rank) {
        rank[now] = val;
        for (int i = 0; i < rel[now].size(); ++i) {
            if (rel[now][i] == p) {
                continue;
            }
            if (rank[rel[now][i]] == -1) {
                int rk = dfs(rank[now]+1, rel[now][i], now, rel, rank);
                if (rk > rank[now]) {
                    res.push_back({now, rel[now][i]});
                } else {
                    val = min(val, rk);
                }
            } else if (rank[rel[now][i]] <= rank[now]) {
                val = min(val, rank[rel[now][i]]);
            }
        }
        return val;
    }
};