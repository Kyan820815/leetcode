//--- Q: 0241. Different Ways to Add Parentheses

//--- method 1: divide & conpuer
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(0, expression.size()-1, expression);
    }
    vector<int> dfs(int start, int end, string &expression) {
        int sum = 0;
        vector<int> res;
        for (int i = start; i <= end; ++i) {
            if (isdigit(expression[i])) {
                sum = sum * 10 + expression[i]-'0';
                continue;
            }
            auto left = dfs(start, i-1, expression);
            auto right = dfs(i+1, end, expression);
            if (expression[i] == '+') {
                for (auto &lv: left) {
                    for (auto &rv: right) {
                        res.push_back(lv+rv);
                    }
                }
            } else if (expression[i] == '-') {
                for (auto &lv: left) {
                    for (auto &rv: right) {
                        res.push_back(lv-rv);
                    }
                }
                
            } else {
                for (auto &lv: left) {
                    for (auto &rv: right) {
                        res.push_back(lv*rv);
                    }
                }
            }
        }
        return !res.size() ? vector<int>{sum} : res;
    }
};