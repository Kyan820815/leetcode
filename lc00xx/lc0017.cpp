//--- Q: 0017. Letter Combinations of a Phone Number
//--- last written: 2023/03/11

//--- method 1: dfs recursion
class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) {
            return {};
        }
        string str = "";
        dfs(0, str, digits);
        return res;
    }
    void dfs(int now, string &str, string &digits) {
        if (now == digits.size()) {
            res.push_back(str);
            return;
        }
        char start = (digits[now]-'2')*3 + (digits[now] > '7' ? 1 : 0) + 'a';
        int sz = digits[now] == '7' || digits[now] == '9' ? 4 : 3;
        for (int i = 0; i < sz; ++i) {
            str += (start+i);
            dfs(now+1, str, digits);
            str.pop_back();
        }
    }
};

//--- method 2: bfs iteration
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) {
            return {};
        }
        vector<string> res;
        unordered_map<char, string> map = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
                                           {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        queue<string> que;
        que.push("");
        while (que.size() && que.front().size() != digits.size()) {
            auto now = que.front();
            que.pop();
            auto pool = map[digits[now.size()]];
            for (auto &ch: pool) {
                que.push(now+ch);
            }
        }
        while (que.size()) {
            res.push_back(que.front());
            que.pop();
        }
        return res;
    }
};
