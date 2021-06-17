//--- Q: 726. Number of Atoms

//--- method 1: map and recursion
class Solution {
public:
    string countOfAtoms(string formula) {
        string res = "";
        int idx = 0;
        auto map = dfs(idx, formula);
        for (auto &str: map) {
            res += str.first;
            int times = str.second;
            if (times > 1) {
                res += to_string(times);
            }
        }
        return res;
    }
    map<string, int> dfs(int &idx, string &str) {
        map<string, int> map;
        string at = "";
        int sum;
        while (idx < str.size()) {
            if (str[idx] == '(') {
                ++idx;
                auto tmp = dfs(idx, str);
                for (auto &atom: tmp) {
                    map[atom.first] += atom.second;
                }
            } else if (str[idx] == ')') {
                ++idx;
                sum = 0;
                while (idx < str.size() && isdigit(str[idx])) {
                    sum = sum*10 + str[idx++]-'0';
                }
                if (sum) {
                    for (auto &atom: map) {
                        atom.second *= sum;
                    }
                }
                return map;
            } else {
                at.push_back(str[idx++]);
                while (idx < str.size() && islower(str[idx])) {
                    at.push_back(str[idx++]);
                }
                sum = 0;
                while (idx < str.size() && isdigit(str[idx])) {
                    sum = sum*10 + str[idx++]-'0';
                }
                map[at] += sum ? sum : 1;
                at = "";
            }
        }
        return map;
    }
};