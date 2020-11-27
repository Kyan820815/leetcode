//--- Q: 1282. Group the People Given the Group Size They Belong To

//--- method 1: collect group size then push to res
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> res, gp(n+1);
        for (int i = 0; i < n; ++i) {
            gp[groupSizes[i]].push_back(i);
            if (gp[groupSizes[i]].size() == groupSizes[i]) {
                res.push_back(gp[groupSizes[i]]);
                gp[groupSizes[i]].clear();
            }
        }
        return res;
    }
};

//--- method 2: nlogn sort
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> res_vec;
        vector<int> idx;
        for (int i = 0; i < n; ++i) {
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&groupSizes](int a, int b){
            return groupSizes[a] < groupSizes[b];
        });
        int i = 0;
        while (i < n) {
            vector<int> res;
            int gs = groupSizes[idx[i]];
            for (int j = 0; j < gs; ++j) {
                res.push_back(idx[i++]);
            }
            res_vec.push_back(res);
        }
        return res_vec;
    }
};