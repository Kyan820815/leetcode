//--- Q: 1152. Analyze User Website Visit Pattern

//--- method 1: map operation
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<string>> record;
        unordered_map<string, int> cnt;
        vector<int> idx;
        int n = username.size();
        for (int i = 0; i < n; ++i) {
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&timestamp](const int &a, const int &b) {
            return timestamp[a] < timestamp[b]; 
        });
        for (int i = 0; i < n; ++i) {
            record[username[idx[i]]].push_back(website[idx[i]]);
        }
        for (auto &node: record) {
            int m = node.second.size();
            unordered_set<string> set;
            for (int i = 0; i < m-2; i++) {
                for (int j = i+1; j < m-1; ++j) {
                    for (int k = j+1; k < m; ++k) {
                        string tmp = node.second[i]+"."+node.second[j]+"."+node.second[k];
                        if (set.find(tmp) == set.end()) {
                            set.insert(tmp);
                        }
                    }
                }
            }
            for (auto &pattern: set) {
                ++cnt[pattern];
            }
        }
        string res;
        int maxv = 0;
        for (auto &m: cnt) {
            if (m.second > maxv) {
                maxv = m.second;
                res = m.first;
            } else if (m.second == maxv && m.first < res) {
                res = m.first;
            }
        }
        vector<string> resvec;
        string tmp = "";
        for (int i = 0; i <= res.size(); ++i) {
            if (i == res.size() || res[i] == '.') {
                resvec.push_back(tmp);
                tmp = "";
            } else {
                tmp += res[i];
            }
        }
        return resvec;
    }
};