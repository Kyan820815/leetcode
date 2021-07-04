//--- Q: 0119. Pascal's Triangle II

//--- method 1-1: O(n) space
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for (int i = 1; i <= rowIndex; ++i) {
            vector tmp = {1};
            for (int j = 1; j < i; ++j) {
                tmp.push_back(res[j]+res[j-1]);
            }
            tmp.push_back(1);
            res = tmp;
        }
        return res;
    }
};

//--- method 2: O(1) space
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for (int i = 1; i <= rowIndex; ++i) {
            vector tmp = {1};
            int pre = 1, now;
            for (int j = 1; j < i; ++j) {
                now = res[j];
                res[j] += pre;
                pre = now;
            }
            res.push_back(1);
        }
        return res;
    }
};