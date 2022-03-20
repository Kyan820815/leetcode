//--- Q: 0254. Factor Combinations

//--- method 1: recursion
class Solution {
public:
    vector<vector<int>> res_vec;
    vector<int> res;
    vector<vector<int>> getFactors(int n) {
        dfs(n);
        return res_vec;
    }
    void dfs(int n) {
        int limit = sqrt(n), i = res.size() ? res.back() : 2;
        for (; i <= limit; ++i) {
            if (n%i == 0) {
                res.push_back(i);
                res.push_back(n/i);
                res_vec.push_back(res);
                res.pop_back();
                dfs(n/i);
                res.pop_back();
            }
        }
    }
};

//--- method 2: iteration
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res_vec;
        queue<pair<vector<int>,pair<int,int>>> que;
        que.push({{},{n,2}});
        while (que.size()) {
            auto now = que.front();
            que.pop();
            int i = now.second.second, val = now.second.first;
            vector<int> tmp = now.first;
            for (;i*i <= val; ++i) {
                if (val % i == 0) {
                    tmp.push_back(i);
                    tmp.push_back(val/i);
                    res_vec.push_back(tmp);
                    tmp.pop_back();
                    que.push({tmp,{val/i,i}});
                    tmp.pop_back();
                }
            }
        }
        return res_vec;
    }
};