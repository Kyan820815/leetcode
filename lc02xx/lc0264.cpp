//--- Q: 0264. Ugly Number II

//--- method 1: dp find the first index greater than now
class Solution {
public:
    int nthUglyNumber(int n) {
        int two = 0, three = 0, five = 0;
        vector<int> res = {1};
        for (int i = 1; i < n; ++i) {
            int val = min(2*res[two], min(3*res[three], 5*res[five]));
            res.push_back(val);
            if (2*res[two] <= res.back()) {
                ++two;
            }
            if (3*res[three] <= res.back()) {
                ++three;
            }
            if (5*res[five] <= res.back()) {
                ++five;
            }
        }
        return res.back();
    }
};