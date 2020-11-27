//--- Q: 1152. Analyze User Website Visit Pattern

//--- method 1: map using
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>> map;
        unordered_map<string, int> pattern_cnt;
        for (int i = 0; i < username.size(); ++i)
            map[username[i]].insert({timestamp[i], website[i]});
        for (auto &u: map) {
            auto web = u.second;
            unordered_set<string> user_pattern;
            for (auto it1 = web.begin(); it1 != web.end(); ++it1)
                for (auto it2 = next(it1); it2 != web.end(); ++it2)
                    for (auto it3 = next(it2); it3 != web.end(); ++it3)
                        user_pattern.insert(it1->second + "?" + it2->second + ":" + it3->second);
            for (auto &up: user_pattern)
                ++pattern_cnt[up];
        }
        string res = "";
        int max_cnt = 0;
        for (auto &pattern: pattern_cnt) {
            if (max_cnt < pattern.second) {
                max_cnt = pattern.second;
                res = pattern.first;
            } else if (max_cnt == pattern.second)
                res = min(res, pattern.first);
        }
        auto first = res.find("?"), second = res.find(":");
        return {res.substr(0, first), res.substr(first+1, second-first-1), res.substr(second+1)};
    }
};

//--- method 2: my version
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<int> idx;
        for (int i = 0; i < username.size(); ++i) {
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&timestamp](int &a, int &b) {
            return timestamp[a] < timestamp[b];
        });
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < idx.size(); ++i) {
            map[username[idx[i]]].push_back(website[idx[i]]);
        }
        unordered_map<string, int> cnt;
        int maxv = 0;
        string min_str;
        for (auto &user: map) {
            vector<string> web = user.second;
            unordered_set<string> set;
            for (int i = 0; i < (int)web.size()-2; ++i) {
                for (int j = i+1; j < (int)web.size()-1; ++j) {
                    for (int k = j+1; k < web.size(); ++k) {
                        string web_str = web[i] + " " + web[j] + " " + web[k];
                        set.insert(web_str);
                    }
                }
            }
            for (auto &str: set) {
                ++cnt[str];
            }
        }
        for (auto &str: cnt) {
            if (str.second > maxv) {
                min_str = str.first;
                maxv = str.second;
            } else if (str.second == maxv && str.first < min_str) {
                min_str = str.first;
            }
        }
        vector<string> res;
        istringstream ss(min_str);
        string str;
        while (ss >> str) {
            res.push_back(str);
        }
        return res;
    }
};