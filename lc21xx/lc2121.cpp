//--- Q: 2121. Intervals Between Identical Elements

//--- method 1: prefix & suffix array
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> res(n, 0);
        unordered_map<int,vector<int>> map;
        for (int i = 0; i < n; ++i) {
            map[arr[i]].push_back(i);
        }
        for (auto &val: map) {
            int m = val.second.size();
            vector<long long> left(m, 0), right(m, 0);
            for (int i = 1, j = m-2; i < m; ++i, --j) {
                left[i] = (val.second[i]-val.second[i-1])*i+left[i-1];
                right[j] = (val.second[j+1]-val.second[j])*(m-1-j)+right[j+1];
            }
            for (int i = 0; i < m; ++i) {
                res[val.second[i]] = left[i] + right[i];
            }
        }
        return res;
    }
};