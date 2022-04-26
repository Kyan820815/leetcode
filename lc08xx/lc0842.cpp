//--- Q: 0842. Split Array into Fibonacci Sequence

//--- method 1: dfs
class Solution {
public:
    using ll = long long;
    vector<int> res;
    vector<int> splitIntoFibonacci(string num) {
        if (dfs(0, num)) {
            return res;
        }
        return {};
    }
    bool dfs(int idx, string &num) {
        int n = res.size();
        if (n > 2) {
            if ((ll)res[n-3]+(ll)res[n-2] != (ll)res[n-1]) {
                return false;
            }
            if (idx == num.size()) {
                return true;
            }
        }
        int cur = 0;
        for (int i = idx; i < num.size(); ++i) {
            if (cur > INT_MAX/10 || cur == INT_MAX/10 && num[i] > '7') {
                break;
            }
            cur = cur*10 + (num[i]-'0');
            res.push_back(cur);
            if (dfs(i+1, num)) {
                return true;
            }
            res.pop_back();
            if (num[idx] == '0') {
                break;
            }
        }
        return false;
    }
};