//--- Q: 0049. Group Anagrams
//--- last written: 2023/06/09

//--- method 1: map and O(n*m) conting sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> map;
        for (auto &str: strs) {
            vector<int> cnt(26, 0);
            string tmp = "";
            for (auto &ch : str) {
                ++cnt[ch-'a'];
            }
            for (auto &v: cnt) {
                tmp += v+'0 ';
            }
            if (map.find(tmp) == map.end()) {
                map[tmp] = res.size();
                res.push_back({str});
            } else {
                res[map[tmp]].push_back(str);
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
        for (auto &str: strs) {
            auto tmp = str;
            sort(tmp.begin(), tmp.end());
            if (map.find(tmp) == map.end()) {
                map[tmp] = res.size();
                res.push_back({str});
            } else {
                res[map[tmp]].push_back(str);
            }
        }
        return res;
    }
};
