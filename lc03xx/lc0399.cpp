//--- Q: 0399. Evaluate Division

//--- method 1: union find with path compression
class Solution {
public:
    unordered_map<string, double> val;
    unordered_map<string, string> parent;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            string ap = findp(equations[i][0]);
            string bp = findp(equations[i][1]);
            if (ap != bp) {
                parent[ap] = bp;
                val[ap] = values[i]*val[equations[i][1]]/val[equations[i][0]];
            }
        }
        for (auto &query: queries) {
            if (parent.find(query[0]) == parent.end() || parent.find(query[1]) == parent.end()) {
                res.push_back(-1.0);
            } else {
                string ap = findp(query[0]);
                string bp = findp(query[1]);
                if (ap != bp) {
                    res.push_back(-1.0);
                } else {
                    res.push_back(val[query[0]]/val[query[1]]);
                }
            }
        }
        return res;
    }
    string findp(string &now) {
        if (parent.find(now) == parent.end()) {
            parent[now] = now;
            val[now] = 1.0;
            return now;
        } else if (parent[now] == now) {
            return now;
        } else {
            auto p = findp(parent[now]);
            // path compression, make all node point to union root
            // and we only propogate only once.
            val[now] *= val[parent[now]];
            return parent[now] = p;
        }
    }
};

//--- method 2: dfs
class Solution {
public:
    unordered_map<string, unordered_map<string, double>> val;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            val[equations[i][0]][equations[i][1]] = values[i];
            val[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        vector<double> res;
        for (auto &query: queries) {
            unordered_set<string> set;
            res.push_back(dfs(query[0], query[1], set));
        }
        return res;
    }
    double dfs(string &cur, string &end, unordered_set<string> &set) {
        set.insert(cur);
        if (val[cur].find(end) != val[cur].end()) {
            return val[cur][end];
        }
        for (auto &next: val[cur]) {
            if (set.find(next.first) == set.end()) {
                auto next_str = next.first;
                auto rtn_val = dfs(next_str, end, set);
                if (rtn_val != -1.0) {
                    return next.second*rtn_val;
                }
            }
        }
        return -1.0;
    }
};