//--- Q: 0524. Longest Word in Dictionary through Deleting

//--- method 1: two pointer
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (auto &wd: d) {
            int i = 0, j = 0;
            while (i < s.size() && j < wd.size()) {
                if (s[i] == wd[j]) {
                    ++j;
                }
                ++i;
            }
            if (j == wd.size()) {
                if (res.size() < wd.size()) {
                    res = wd;
                } else if (res.size() == wd.size() && res > wd) {
                    res = wd;
                }
            }
        }
        return res;
    }
};

//--- method 2: faster two pointer
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        vector<vector<int>> map(s.size(), vector<int>(26, s.size()));
        for (int i = s.size()-1; i >= 0; --i) {
            map[i][s[i]-'a'] = i;
            if (i > 0) {
                map[i-1] = map[i];
            }
        }
        for (auto &wd: dictionary) {
            int idx = 0, i = 0;
            while (i < wd.size()) {
                if (idx == s.size() || map[idx][wd[i]-'a'] == s.size()) {
                    break;
                }
                idx = map[idx][wd[i]-'a']+1;
                ++i;
            }
            if (i == wd.size()) {
                if (res.size() < wd.size()) {
                    res = wd;
                } else if (res.size() == wd.size() && res > wd) {
                    res = wd;
                }
            }
        }
        return res;
    }
};

//--- method 3: do all in once
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<vector<pair<int,int>>> map(26);
        string res = "";
        for (int i = 0; i < dictionary.size(); ++i) {
            map[dictionary[i][0]-'a'].push_back({i, 0});
        }
        for (int i = 0; i < s.size(); ++i) {
            auto vec = map[s[i]-'a'];
            if (!vec.size()) {
                continue;
            }
            map[s[i]-'a'].clear();
            for (auto &p: vec) {
                int dic_idx = p.first, wd_idx = p.second;
                if (wd_idx+1 == dictionary[dic_idx].size()) {
                    if (res.size() < dictionary[dic_idx].size()) {
                        res = dictionary[dic_idx];
                    } else if (res.size() == dictionary[dic_idx].size() && res > dictionary[dic_idx]) {
                        res = dictionary[dic_idx];
                    }
                } else {
                    map[dictionary[dic_idx][wd_idx+1]-'a'].push_back({dic_idx, wd_idx+1});
                }
            }
        }
        return res;
    }
};

//--- method 3: