//--- Q: 0832. Flipping an Image

//--- method 1: find equal value and xor
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size(), col = image[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col/2; ++j) {
                if (image[i][j] == image[i][col-j-1]) {
                    image[i][j] ^= 1;
                    image[i][col-j-1] ^= 1;
                }
            }
            if (col&1) {
                image[i][col/2] ^= 1;
            }
        }
        return image;
    }
};