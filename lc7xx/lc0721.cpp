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
            int qsize = 1;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent, head;
        unordered_map<string, vector<string>> list;
        vector<vector<string>> res;
        for (int i = 0; i < accounts.size(); ++i) {
            string ap = findp(accounts[i][1], parent, list);
            head[ap] = accounts[i][0];
            for (int j = 2; j < accounts[i].size(); ++j) {
                string ap = findp(accounts[i][1], parent, list);
                string bp = findp(accounts[i][j], parent, list);
                if (ap != bp) {
                    if (list[ap].size() < list[bp].size()) {
                        parent[ap] = bp;
                        list[bp].insert(list[bp].end(), list[ap].begin(), list[ap].end());
                        list.erase(ap);
                    } else {
                        parent[bp] = ap;
                        list[ap].insert(list[ap].end(), list[bp].begin(), list[bp].end());
                        list.erase(bp);
                    }
                }
            }
        }
        for (auto &m: list) {
            string x = m.first;
            res.push_back({head[x]});
            sort(list[x].begin(), list[x].end());
            res.back().insert(res.back().end(), list[x].begin(), list[x].end());
        }
        return res;
    }
    string findp(string &now, unordered_map<string, string> &parent, unordered_map<string, vector<string>> &list) {
        if (parent.find(now) == parent.end()) {
            parent[now] = now;
            list[now].push_back(now);
        } else if (now != parent[now]){
            return parent[now] = findp(parent[now], parent, list);
        }
        return parent[now];
    }
};
