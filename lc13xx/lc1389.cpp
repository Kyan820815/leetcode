//--- Q: 1389. Create Target Array in the Given Order

//--- method 1: divide & conquer
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<vector<int>> idx_pair;
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            idx_pair.push_back({i, index[i]});
        }
        divide(0, n-1, idx_pair);
        for (int i = 0; i < res.size(); ++i) {
            res[idx_pair[i][1]] = nums[idx_pair[i][0]];
        }
        return res;
    }
    void divide(int start, int end, vector<vector<int>> &idx_pair) {
        if (start < end) {
            int mid = (end - start) / 2 + start;
            divide(start, mid, idx_pair);
            divide(mid+1, end, idx_pair);
            conquer(start, mid, end, idx_pair);
        }
    }
    void conquer(int start, int mid, int end, vector<vector<int>> &idx_pair) { 
        int i = start, j = mid+1;
        int shift = 0;
        vector<vector<int>> copy;
        while (i <= mid && j <= end) {
            if (idx_pair[i][1] + shift >= idx_pair[j][1]) {
                copy.push_back(idx_pair[j++]);
                ++shift;
            } else {
                idx_pair[i][1] += shift;
                copy.push_back(idx_pair[i++]);
            }
        }
        while (i <= mid) {
            idx_pair[i][1] += shift;
            copy.push_back(idx_pair[i++]);
        }
        while (j <= end) {
            copy.push_back(idx_pair[j++]);
        }
        for (int i = start; i <= end; ++i) {
            idx_pair[i] = copy[i-start];
        }
    }
};

//--- method 2:
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j >= index[i]+1; --j) {
                res[j] = res[j-1];
            }
            res[index[i]] = nums[i];
        }
        return res;
    }
};