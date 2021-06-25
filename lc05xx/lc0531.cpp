//--- Q: 531. Lonely Pixel I

//--- method 1: skip if there is a 'B' in certain row or col 
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row = picture.size(), col = picture[0].size(), res = 0;
        vector<int> usedr(row, 0), usedc(col, 0);
        for (int i = 0; i < row; ++i) {
            if (usedr[i]) {
                continue;
            }
            for(int j = 0; j < col; ++j) {
                if (usedc[j]) {
                    continue;
                }
                if (picture[i][j] == 'B') {
                    if (find(i, j, usedr, usedc, picture)) {
                        ++res;
                    }
                }
            }
        }
        return res;
    }
    bool find(int i, int j, vector<int> &usedr, vector<int> &usedc, vector<vector<char>>& picture) {
        int row = picture.size(), col = picture[0].size();
        bool find = true;
        usedr[i] = usedc[j] = 1;
        for (int c = 0; c < col; ++c) {
            if (c != j && picture[i][c] == 'B') {
                find = false;
                usedc[c] = 1;
            }
        }
        for (int r = 0; r < row; ++r) {
            if (r != i && picture[r][j] == 'B') {
                find = false;
                usedr[r] = 1;
            }
        }
        return find;
    }
};

//--- method 2: check each row or col has how many 'B'
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row = picture.size(), col = picture[0].size(), res = 0;
        vector<int> usedr(row, 0), usedc(col, 0);
        for (int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B') {
                    ++usedr[i];
                    ++usedc[j];
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B' && usedr[i] == 1 && usedc[j] == 1) {
                    ++res;
                }
            }
        }
        return res;
    }
};

//--- method 3: better version of method 2, from O(m+n) space to O(n) space
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row = picture.size(), col = picture[0].size(), res = 0;
        vector<int> cc(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B') {
                    ++cc[j];
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            int cnt = 0, c;
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B') {
                    c = j;
                    ++cnt;
                }
            }
            if (cnt == 1 && cc[c] == 1) {
                ++res;
            }
        }
        return res;
    }
};