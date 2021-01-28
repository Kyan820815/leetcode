//--- Q: 1436. Destination City

//--- method 1: set finding
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> set;
        for (auto &p: paths) {
            set.insert(p[0]);
        }
        for (auto &p: paths) {
            if (set.find(p[1]) == set.end()) {
                return p[1];
            }
        }
        return "";
    }
};