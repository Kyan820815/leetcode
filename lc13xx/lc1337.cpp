//--- Q: 1337. The K Weakest Rows in a Matrix

//--- method 1: bucket sort
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> cnt(101);
        vector<int> res;
        for (int i = 0; i < mat.size(); ++i) {
            int j;
            for (j = 0; j < mat[i].size() && mat[i][j] == 1; ++j);
            cnt[j].push_back(i);
        }
        for (int i = 0; i <= 100 && k; ++i) {
            if (cnt[i].size()) {
                for (int j = 0; j < cnt[i].size() && k; ++j) {
                    res.push_back(cnt[i][j]);
                    --k;
                }
            }
        }
        return res;
    }
};

//--- method 2: priority queue
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        auto comp = [](pair<int,int> &a, pair<int,int> &b) {
            return a.first < b.first || a.first == b.first && a.second < b.second;  
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> que(comp);
        vector<int> res(k);
        int row = mat.size(), col = mat[0].size();
        for (int i = 0; i < row; ++i) {
            int sod = 0;
            for (int j = 0; j < col; ++j) {
                sod += mat[i][j];
            }
            que.push({sod, i});
            if (que.size() > k) {
                que.pop();
            }
        }
        while (que.size()) {
            auto index = que.top().second;
            que.pop();
            res[que.size()] = index;
        }
        return res;
    }
};