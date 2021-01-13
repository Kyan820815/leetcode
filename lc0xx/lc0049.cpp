//--- Q: 049. Group Anagrams

//--- method 1: map and O(n*m) conting sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> map;
        for (int i = 0; i < strs.size(); ++i) {
            string now = "";
            vector<int> cnt(26, 0);
            for (int j = 0; j < strs[i].size(); ++j) {
                ++cnt[strs[i][j]-'a'];
            }
            for (int j = 0; j < 26; ++j) {
                now.push_back(cnt[j]+'0');
                now.push_back(',');
            }
            if (map.find(now) == map.end()) {
                map[now] = res.size();
                res.push_back({strs[i]});
            } else {
                res[map[now]].push_back(strs[i]);
            }
        }
        return res;
    }
};

//--- method 2: map and O(nlonn) sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> map;
        for (int i = 0; i < strs.size(); ++i) {
            string now = strs[i];
            sort(now.begin(), now.end());
            if (map.find(now) == map.end()) {
                map[now] = res.size();
                res.push_back({strs[i]});
            } else {
                res[map[now]].push_back(strs[i]);
            }
        }
        return res;
    }
};