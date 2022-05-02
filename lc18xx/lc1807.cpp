//--- Q: 1807. Evaluate the Bracket Pairs of a String

//--- method 1: string processing
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for (auto &pair: knowledge) {
            map[pair[0]] = pair[1];
        }
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                string key = "";
                ++i;
                while (s[i] != ')') {
                    key += s[i++];
                }
                if (map.find(key) != map.end()) {
                    res += map[key];
                } else {
                    res += "?";
                }
            } else {
                res += s[i];
            }
        }
        return res;
    }
};