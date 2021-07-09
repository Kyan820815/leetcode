//--- Q: 399. Evaluate Division

//--- method 1: union find with path compression
class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, double> val;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            string ap = findP(equations[i][0]);
            string bp = findP(equations[i][1]);
            parent[ap] = bp;
            val[ap] = val[equations[i][1]] * values[i] / val[equations[i][0]];
        }
        for (int i = 0; i < queries.size(); ++i) {
            if (parent.find(queries[i][0]) == parent.end() || parent.find(queries[i][1]) == parent.end())
                res.push_back(-1.0);
            else {
                string ap = findP(queries[i][0]);
                string bp = findP(queries[i][1]);
                if (ap == bp) {
                    res.push_back(val[queries[i][0]] / val[queries[i][1]]);
                } else {
                    res.push_back(-1.0);
                }
            }
        }
        return res;
    }
    string findP(string &now) {
        if (parent.find(now) == parent.end()) {
            parent[now] = now;
            val[now] = 1.0;
            return now;
        }
        if (now != parent[now]) {
            string p = findP(parent[now]);
            // path compression, make all node point to union root
            // and we only propogate only once.
            val[now] *= val[parent[now]];
            parent[now] = p;
            return p;
        }
        return now;
    }
};

//--- method 2: dfs
class Solution {
public:
    unordered_map<string, unordered_map<string, double>> rel;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            rel[equations[i][0]][equations[i][1]] = values[i];
            rel[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        vector<double> res;
        for (auto &query: queries) {
            unordered_set<string> set;
            res.push_back(dfs(query[0], query[1], set));
        }
        return res;
    }
    double dfs(string &now, string &end, unordered_set<string> &set) {
        if (rel[now].find(end) != rel[now].end()) {
            return rel[now][end];
        }
        for (auto &next: rel[now]) {
            if (set.find(next.first) == set.end()) {
                set.insert(next.first);
                auto next_c = next.first;
                auto rtn_val = dfs(next_c, end, set);
                if (rtn_val != -1.0) {
                    return rtn_val*next.second;
                }
            }
        }
        return -1.0;
    }
};