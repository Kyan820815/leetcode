//--- Q: 0524. Longest Word in Dictionary through Deleting

//--- method 1: two pointer
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for (auto &wd: dictionary) {
            int i, j;
            for (i = 0, j = 0; i < s.size() && j < wd.size(); ++i) {
                if (s[i] == wd[j]) {
                    ++j;
                }
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
        vector<vector<int>> cnt(s.size(), vector<int>(26, s.size()));
        for (int i = s.size()-1; i >= 0; --i) {
            cnt[i][s[i]-'a'] = i;
            if (i > 0) {
                cnt[i-1] = cnt[i];
            }
        }
        string res = "";
        for (auto &wd: dictionary) {
            int sidx = 0, find = 1, i;
            for (i = 0; i < wd.size(); ++i) {
                if (sidx == s.size() || cnt[sidx][wd[i]-'a'] == s.size()) {
                    break;
                }
                sidx = cnt[sidx][wd[i]-'a']+1;
            }
            if (i == wd.size()) {
                if (res.size() < wd.size() || res.size() == wd.size() && res > wd) {
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
        vector<vector<pair<int,int>>> cnt(26);
        for (int i = 0; i < dictionary.size(); ++i) {
            cnt[dictionary[i][0]-'a'].push_back({i,0});
        }
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            auto vec = cnt[s[i]-'a'];
            cnt[s[i]-'a'].clear();
            for (auto &dic: vec) {
                auto dic_idx = dic.first, wd_idx = dic.second;
                if (wd_idx == dictionary[dic_idx].size()-1) {
                    if (res.size() < dictionary[dic_idx].size()) {
                        res = dictionary[dic_idx];
                    } else if (res.size() == dictionary[dic_idx].size() && res > dictionary[dic_idx]) {
                        res = dictionary[dic_idx];
                    }
                } else {
                    cnt[dictionary[dic_idx][wd_idx+1]-'a'].push_back({dic_idx, wd_idx+1});
                }
            }
        }
        return res;
    }
};
