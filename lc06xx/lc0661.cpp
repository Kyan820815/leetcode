//--- Q: 0661. Image Smoother

//--- method 1: bit oeration with 16 bit for each element
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1},{0,0}};
        int row = img.size(), col = img[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int sum = 0, cnt = 0;
                for (auto &dir: dirs) {
                    int nr = i+dir[0];
                    int nc = j+dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                        continue;
                    }
                    ++cnt;
                    sum += (img[nr][nc]&255);
                }
                img[i][j] |= ((sum/cnt) << 8);
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                img[i][j] >>= 8;
            }
        }
        return img;
    }
};