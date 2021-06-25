//--- Q: 1422. Maximum Score After Splitting a String

//--- method 1: find formula, one pass
class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, n = s.size(), max_zeros = INT_MIN;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ++ones;
            } else {
                ++zeros;
            }
            if (i != s.size()-1) {
                max_zeros = max(max_zeros, zeros-ones);
            }
        }
        return max_zeros+ones;
    }
};