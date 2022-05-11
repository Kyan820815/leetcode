//--- Q: 1375. Number of Times Binary String Is Prefix-Aligned

//--- method 1: find max value
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int res = 0, maxv = 0;
        for (int i = 0; i < flips.size(); ++i) {
            maxv = max(maxv, flips[i]);
            res += maxv == i+1;
        }
        return res;
    }
};