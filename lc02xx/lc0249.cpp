//--- Q: 0249. Group Shifted Strings

//--- method 1: map operation
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, int> map;
        vector<vector<string>> res;
        for (auto &str: strings) {
            string tmp = "a";
            auto diff = str[0]-'a';
            for (int i = 1; i < str.size(); ++i) {
                auto idx = ((str[i]-'a')-diff+26)%26;
                tmp.push_back('a'+idx);
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