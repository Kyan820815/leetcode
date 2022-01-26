//--- Q: 1104. Path In Zigzag Labelled Binary Tree

//--- method 1: level symmetric, height condition
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int h = 0, tmp = label;
        while (tmp != 1) {
            tmp >>= 1;
            ++h;
        }
        res.push_back(label);
        while (h) {
            label = (1 << h) - (label>>1) + (1 << (h-1))-1;
            res.push_back(label);
            h--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//--- method 2: label condition
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int h = 0, tmp = label;
        while (tmp > 1) {
            tmp >>= 1;
            h++;
        }
        while (label > 1) {
            res.push_back(label);
            label = (1 << h) - (label>>1) + (1 << (h-1))-1;
            h--;
        }
        res.push_back(label);
        reverse(res.begin(), res.end());
        return res;
    }
};