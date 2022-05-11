//--- Q: 1868. Product of Two Run-Length Encoded Arrays

//--- method 1: two pointers
class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int i = 0, j = 0, n = encoded1.size(), m = encoded2.size();
        vector<vector<int>> res;
        while (i < n && j < m) {
            int cnt, val = encoded1[i][0]*encoded2[j][0];
            if (encoded1[i][1] > encoded2[j][1]) {
                cnt = encoded2[j][1];
                encoded1[i][1] -= encoded2[j++][1];
            } else if (encoded1[i][1] < encoded2[j][1]) {
                cnt = encoded1[i][1];
                encoded2[j][1] -= encoded1[i++][1];
            } else {
                cnt = encoded2[j][1];
                ++i,++j;
            }
            if (res.size() && res.back()[0] == val) {
                res.back()[1] += cnt;
            } else {
                res.push_back({val, cnt});
            }
        }
        return res;
    }
};