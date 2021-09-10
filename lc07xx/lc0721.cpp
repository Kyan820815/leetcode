//--- Q: 0721. Accounts Merge

//--- method 1: bfs with queue
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        vector<int> visit(accounts.size(), 0);
        unordered_map<string, vector<int>> map;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                map[accounts[i][j]].push_back(i);
            }
        }
        for (int i = 0; i < accounts.size(); ++i) {
            if (!visit[i]) {
                visit[i] = 1;
                queue<int> que;
                que.push(i);
                set<string> tmp;
                while (que.size()) {
                    auto qsize = que.size();
                    while (qsize--) {
                        auto now = que.front();
                        que.pop();
                        for (int j = 1; j < accounts[now].size(); ++j) {
                            tmp.insert(accounts[now][j]);
                            for (auto &id: map[accounts[now][j]]) {
                                if (!visit[id]) {
                                    visit[id] = 1;
                                    que.push(id);
                                }
                            }
                        }
                    }
                }
                res.push_back({accounts[i][0]});
                res.back().insert(res.back().end(), tmp.begin(), tmp.end());
            }
        }
        return res;
    }
};

//--- method 2: union find
class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, vector<string>> set;
    unordered_map<string, string> head;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (int i = 0; i < accounts.size(); ++i) {
            string ap = findp(accounts[i][1]);
            head[ap] = accounts[i][0];
            for (int j = 2; j < accounts[i].size(); ++j) {
                string bp = findp(accounts[i][j]);
                if (ap != bp) {
                    if (set[ap].size() < set[bp].size()) {
                        parent[ap] = bp;
                        set[bp].insert(set[bp].end(), set[ap].begin(), set[ap].end());
                        set.erase(ap);
                    } else {
                        parent[bp] = ap;
                        set[ap].insert(set[ap].end(), set[bp].begin(), set[bp].end());
                        set.erase(bp);
                    }
                }
                ap = findp(accounts[i][1]);
            }
        }
        vector<vector<string>> res;
        for (auto &uni: set) {
            vector<string> tmp = {head[uni.first]};
            sort(uni.second.begin(), uni.second.end());
            tmp.insert(tmp.end(), uni.second.begin(), uni.second.end());
            res.push_back(tmp);
        }
        return res;
    }
    string findp(string &now) {
        if (parent.find(now) == parent.end()) {
            set[now].push_back(now);
            return parent[now] = now;
        } else if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};
