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
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        map<pair<string, string>, double> m;
        unordered_map<string, vector<string>> rel;
        for (int i = 0; i < equations.size(); ++i) {
            rel[equations[i][0]].push_back(equations[i][1]);
            rel[equations[i][1]].push_back(equations[i][0]);
            m.insert({{equations[i][0], equations[i][1]}, values[i]});
            m.insert({{equations[i][1], equations[i][0]}, 1/values[i]});
        }
        for (int i = 0; i < queries.size(); ++i) {
            string cur = queries[i][0], dst = queries[i][1];
            if (!rel[cur].size() || !rel[dst].size()) {
                res.push_back(-1.0);
            } else if (cur == dst) {
                res.push_back(1.0);
            } else {
                double nowv = dfs("-", cur, dst, rel, m);
                if (nowv == 0) {
                    res.push_back(-1.0);
                } else {
                    m.insert({{cur, dst}, nowv});
                    m.insert({{dst, cur}, 1/nowv});
                    res.push_back(nowv);
                }
            }
        }
        return res;
    }
    double dfs(string last, string &now, string &dst, unordered_map<string, vector<string>> &rel, map<pair<string, string>, double> &m) {
        if (m.find({now, dst}) != m.end()) {
            return m[{now, dst}];
        }
        if (now == dst) {
            return 1.0;
        }
        for (int i = 0; i < rel[now].size(); ++i) {
            if (rel[now][i] == last) {
                continue;
            }
            double curv = dfs(now, rel[now][i], dst, rel, m);
            if (curv != 0) {
                return m[{now, rel[now][i]}] * curv;
            }
        }
        return 0;
    }
};