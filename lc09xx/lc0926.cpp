//--- Q: 0926. Flip String to Monotone Increasing

//--- method 1: dp iteration
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, res = 0;
        for (auto &ch: s) {
            if (ch == '1') {
                ++ones;
            } else {
                res = min(res+1, ones);
            }
        }
        return res;
    }
};