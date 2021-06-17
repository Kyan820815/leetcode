//--- Q: 835. Image Overlap

//--- method 1: find difference for each pixel
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int row = img1.size(), col = img1[0].size(), res = 0;
        unordered_map<int, int> cnt;
        unordered_set<int> cnt1, cnt2;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (img1[i][j]) {
                    cnt1.insert(i*100+j);
                }
                if (img2[i][j]) {
                    cnt2.insert(i*100+j);
                }
            }
        }
        for (auto &n1: cnt1) {
            for (auto &n2: cnt2) {
                ++cnt[n2-n1];
            }
        }
        for (auto &num: cnt) {
            res = max(res, num.second);
        }
        return res;
    }
};