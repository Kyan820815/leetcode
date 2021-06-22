//--- Q: 1773. Count Items Matching a Rule

//--- method 1: count
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int res = 0;
        unordered_map<string, int> map = {{"type",0}, {"color",1}, {"name",2}};
        for (auto &item: items) {
            res += item[map[ruleKey]] == ruleValue;
        }
        return res;
    }
};