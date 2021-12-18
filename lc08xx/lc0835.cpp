//--- Q: 0835. Image Overlap

//--- method 1: find difference for each pixel
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int row = img1.size(), col = img2.size();
        unordered_set<int> set1, set2;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (img1[i][j]) {
                    set1.insert(i*100+j);
                }
                if (img2[i][j]) {
                    set2.insert(i*100+j);
                }
            }
        }
        unordered_map<int,int> cnt;
        for (auto &v1: set1) {
            for (auto &v2: set2) {
                ++cnt[v1-v2];
            }
        }
        int res = 0;
        for (auto &v: cnt) {
            res = max(res, v.second);
        }
        return res;
    }
};