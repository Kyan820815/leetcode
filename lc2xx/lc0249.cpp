//--- Q: 249. Group Shifted Strings

//--- method 1: map operation
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for (int i = 0 ; i < strings.size(); ++i) {
            string m = "";
            for (int j = 0; j < strings[i].size()-1; ++j) {
                int diff = strings[i][j+1]-strings[i][j];
                diff = (diff + 26) % 26;
                m += 'a' + diff;
            }
            map[m].push_back(strings[i]);
        }
        for (auto &m: map)
            res.push_back(m.second);
        return res;
    }
};