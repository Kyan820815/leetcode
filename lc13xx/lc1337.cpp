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

//--- method 2: binary search & priority queue
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
            int left = 0, right = col-1;
            while (left <= right) {
                int mid = (right-left)/2 + left;
                if (!mat[i][mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
            que.push({left, i});
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

//--- method 3: binary search & set
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        set<pair<int,int>> val;
        int row = mat.size(), col = mat[0].size();
        for (int i = 0; i < row; ++i) {
            int left = 0, right = col-1;
            while (left <= right) {
                int mid = (right-left)/2 + left;
                if (!mat[i][mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
            val.insert({left, i});
        }
        for (auto i = val.begin(); k > 0; ++i, --k) {
            res.push_back(i->second);
        }
        return res;
    }
};