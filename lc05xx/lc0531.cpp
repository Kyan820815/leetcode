//--- Q: 0531. Lonely Pixel I

//--- method 1: check each row or col has how many 'B'
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row = picture.size(), col = picture[0].size(), res = 0;
        vector<int> rcnt(row, 0), ccnt(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B') {
                    ++rcnt[i], ++ccnt[j];
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B' && rcnt[i] == 1 && ccnt[j] == 1) {
                    ++res;
                }
            }
        }
        return res;
    }
};

//--- method 2: better version of method 2, from O(m+n) space to O(n) space
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row = picture.size(), col = picture[0].size(), res = 0;
        vector<int> ccnt(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B') {
                    ++ccnt[j];
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            int valid = 0, cnt = 0;
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B') {
                    if (++cnt > 1) {
                        break;
                    }
                    valid |= (ccnt[j] == 1);
                }
            }
            if (valid && cnt == 1) {
                ++res;
            }
        }
        return res;
    }
};