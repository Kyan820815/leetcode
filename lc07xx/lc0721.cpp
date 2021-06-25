//--- Q: 721. Accounts Merge

//--- method 1: bfs with queue
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> map;
        vector<vector<string>> res;
        int n = accounts.size();
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j)
                map[accounts[i][j]].push_back(i);
        }
        vector<int> visit(n, 0);
        for (int i = 0; i < n; ++i) {
            if (visit[i])
                continue;
            queue<int> que{{i}};
            set<string> mail;
            while (que.size()) {
                auto now = que.front();
                que.pop();
                for (int j = 1; j < accounts[now].size(); ++j) {
                    mail.insert(accounts[now][j]);
                    for (int k = 0; k < map[accounts[now][j]].size(); ++k) {
                        if (!visit[map[accounts[now][j]][k]]) {
                            visit[map[accounts[now][j]][k]] = 1;
                            que.push(map[accounts[now][j]][k]);
                        }
                    }
                }
            }
            res.push_back({accounts[i][0]});
            vector<string> now_res(mail.begin(), mail.end());
            res.back().insert(res.back().end(), now_res.begin(), now_res.end());
        }
        return res;
    }
};

class Solution {
public:
    unordered_map<string, vector<string>> group;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> head, parent;
        for (int i = 0; i < accounts.size(); ++i) {
            string ap = findp(accounts[i][1], parent);
            head[ap] = accounts[i][0];
            for (int j = 2; j < accounts[i].size(); ++j) {
                string bp = findp(accounts[i][j], parent);
                if (ap != bp) {
                    if (group[ap].size() < group[bp].size()) {
                        parent[ap] = bp;
                        group[bp].insert(group[bp].end(), group[ap].begin(), group[ap].end());
                        group.erase(ap);
                    } else {
                        parent[bp] = ap;
                        group[ap].insert(group[ap].end(), group[bp].begin(), group[bp].end());
                        group.erase(bp);
                    }
                }
                ap = findp(accounts[i][1], parent);
            }
        }
        vector<vector<string>> res;
        for (auto &s: group) {
            res.push_back({head[s.first]});
            sort(s.second.begin(), s.second.end());
            res.back().insert(res.back().end(), s.second.begin(), s.second.end());
        }
        return res;
    }
    string findp(string now, unordered_map<string, string> &parent) {
        if (parent.find(now) == parent.end()) {
            group[now].push_back(now);
            return parent[now] = now;
        } else {
            return parent[now] == now ? now : findp(parent[now], parent);
        }
    }
};
