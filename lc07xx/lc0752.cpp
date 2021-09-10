//--- Q: 0752. Open the Lock

//--- method 1: bfs
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ban(deadends.begin(), deadends.end());
        if (ban.find("0000") != ban.end() || ban.find(target) != ban.end()) {
            return -1;
        }
        int res = 0;
        queue<string> que;
        que.push("0000");
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (now == target) {
                    return res;
                }
                for (int i = 0; i < now.size(); ++i) {
                    for (int j = 1; j < 10; j+=8) {
                        auto tmp = now;
                        tmp[i] = ((tmp[i]-'0'+j)%10)+'0';
                        if (ban.find(tmp) == ban.end()) {
                            ban.insert(tmp);
                            que.push(tmp);
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
        unordered_set<string> ban(deadends.begin(), deadends.end());
        int res = 0, start = 0, end = 1, next = 2;
        vector<unordered_set<string>> data(3);
        if (ban.find(target) != ban.end() || ban.find("0000") != ban.end()) {
            return -1;
        }
        if (target == "0000") {
            return res;
        }
        data[start].insert("0000");
        data[end].insert(target);
        while (data[start].size()) {
            for (auto &str: data[start]) {
                for (int i = 0; i < str.size(); ++i) {
                    for (int j = 1; j < 10; j+=8) {
                        auto tmp = str;
                        tmp[i] = ((tmp[i]-'0'+j)%10)+'0';
                        if (data[end].find(tmp) != data[end].end()) {
                            return res+1;
                        } else if (ban.find(tmp) == ban.end()) {
                            ban.insert(tmp);
                            data[next].insert(tmp);
                        }
                    }
                }
            }
            ++res;
            data[start] = data[next];
            data[next].clear();
            if (data[start].size() > data[end].size()) {
                swap(start, end);
            }
        }
        return -1;
    }
};