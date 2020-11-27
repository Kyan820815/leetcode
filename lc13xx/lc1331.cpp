//--- Q: 1331. Rank Transform of an Array

//--- method 1: sort index
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> idx, res(arr.size());
        if (!arr.size()) {
            return res;
        }
        for (int i = 0; i < arr.size(); ++i) {
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&arr](int a, int b) {
            return arr[a] < arr[b];
        });
        int r = 1;
        res[idx[0]] = r;
        for (int i = 1; i < idx.size(); ++i) {
            if (arr[idx[i]] != arr[idx[i-1]]) {
                ++r;
            }
            res[idx[i]] = r;
        }
        return res;
    }
};