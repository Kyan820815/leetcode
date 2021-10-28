//--- Q: 0792. Number of Matching Subsequences

//--- method 1: character operation with length processing
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int,int>>> cnt(26);
        for (int i = 0; i < words.size(); ++i) {
            cnt[words[i][0]-'a'].push_back({i,0});
        }
        int res = 0;
        for (auto &ch: s) {
            auto vec = cnt[ch-'a'];
            cnt[ch-'a'].clear();
            for (auto &element: vec) {
                if (element.second == words[element.first].size()-1) {
                    ++res;
                } else {
                    cnt[words[element.first][element.second+1]-'a'].push_back({element.first,element.second+1});
                }
            }
            
        }
        return res;
    }
};
//--- method 2: two pointer
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        for (auto &wd: words) {
            int i, j;
            for (i = 0, j = 0; i < s.size(); ++i) {
                if (s[i] == wd[j]) {
                    ++j;
                }
            }
            res += j == wd.size();
        }
        return res;
    }
};

//--- method 3: two pointer and hashmap
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        vector<vector<int>> appear(s.size(), vector<int>(26, s.size()));
        for (int i = s.size()-1; i >= 0; --i) {
            appear[i][s[i]-'a'] = i;
            if (i > 0) {
                appear[i-1] = appear[i];
            }
        }
        for (auto &wd: words) {
            int sidx = 0, find = 1;
            for (auto &ch: wd) {
                if (sidx == s.size() || appear[sidx][ch-'a'] == s.size()) {
                    find = 0;
                    break;
                }
                sidx = appear[sidx][ch-'a']+1;
            }
            if (find) {
                ++res;
            }
        }
        return res;
    }
};