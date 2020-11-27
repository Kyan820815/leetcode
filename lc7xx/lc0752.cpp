//--- Q: 752. Open the Lock

//--- method 1: bfs
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int res = 0;
        unordered_set<string> set(deadends.begin(), deadends.end());
        if (set.find("0000") != set.end()) {
            return -1;
        }
        queue<string> que{{"0000"}};
        set.insert("0000");
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                string tmp;
                for (int j = 0; j < 4; ++j) {
                    for (int k = 1; k <= 9; k += 8) {
                        tmp = now;
                        tmp[j] = ((tmp[j]-'0' + k) % 10) + '0';
                        if (set.find(tmp) == set.end()) {
                            if (tmp == target) {
                                return res + 1;
                            } else {
                                set.insert(tmp);
                                que.push(tmp);
                            }
                        }
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};

//--- method 2: bi-directional bfs
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ban(deadends.begin(), deadends.end()), used;
        vector<unordered_set<string>> level(3);
        int start = 0, end = 1, next = 2, res = 0;
        if (ban.find("0000") != ban.end()) {
            return -1;
        } else if (target == "0000") {
            return 0;
        }
        level[start].insert("0000");
        level[end].insert(target);
        used.insert("0000");
        used.insert(target);
        while (level[start].size()) {
            for (auto &s: level[start]) {
                for (int i  = 0; i < s.size(); ++i) {
                    for (int k = 1; k <= 9; k += 8) {
                        string now = s;
                        now[i] = (now[i]-'0'+k) % 10 + '0';
                        if (ban.find(now) == ban.end()) {
                            if (level[end].find(now) != level[end].end()) {
                                return res+1;
                            }
                            if (used.find(now) == used.end()) {
                                level[next].insert(now);
                                used.insert(now);
                            }
                        }
                    }
                }
            }
            level[start] = level[next];
            if (level[start].size() > level[end].size()) {
                swap(start, end);
            }
            level[next].clear();
            ++res;
        }
        return -1;
    }
};