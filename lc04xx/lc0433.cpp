//--- Q: 0433. Minimum Genetic Mutation

//--- method 1: one way bfs
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bk(bank.begin(), bank.end());
        if (bk.find(end) == bk.end()) {
            return -1;
        }
        bk.erase(start);
        vector<char> gene = {'A','T','C','G'};
        int res = 0;
        queue<string> que;
        que.push(start);
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto str = que.front();
                que.pop();
                if (str == end) {
                    return res;
                }
                for (int i = 0; i < str.size(); ++i) {
                    auto tmp = str;
                    for (const auto &ch: gene) {
                        tmp[i] = ch;
                        if (tmp == str) {
                            continue;
                        }
                        if (bk.find(tmp) != bk.end()) {
                            bk.erase(tmp);
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
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bk(bank.begin(), bank.end());
        vector<unordered_set<string>> data(3);
        int st = 0, nt = 1, ed = 2;
        if (bk.find(end) == bk.end()) {
            return -1;
        }
        bk.erase(start);
        bk.erase(end);
        data[st].insert(start);
        data[ed].insert(end);
        vector<char> gene = {'A','T','C','G'};
        int res = 0;
        while (data[st].size()) {
            for (auto &str: data[st]) {
                for (int i = 0; i < str.size(); ++i) {
                    auto tmp = str;
                    for (const auto &ch: gene) {
                        tmp[i] = ch;
                        if (tmp == str) {
                            continue;
                        }
                        if (data[ed].find(tmp) != data[ed].end()) {
                            return res+1;
                        } else if (bk.find(tmp) != bk.end()) {
                            bk.erase(tmp);
                            data[nt].insert(tmp);
                        }
                    }
                }
            }
            swap(data[st], data[nt]);
            data[nt].clear();
            if (data[st].size() > data[ed].size()) {
                swap(st, ed);
            }
            ++res;
        }
        return -1;
    }
};