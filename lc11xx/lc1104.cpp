//--- Q: 1104. Path In Zigzag Labelled Binary Tree

//--- method 1: level symmetric
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int level = 0, tmp = label;
        while (tmp) {
            tmp /= 2;
            ++level;
        }
        res.resize(level);
        res[level-1] = label;
        for (int i = res.size()-1; i > 0; --i) {
            res[i-1] = pow(2,i-1)-1 + pow(2,i)-res[i]/2;
        }
        return res;
    }
};