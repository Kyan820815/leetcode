//--- Q: 926. Flip String to Monotone Increasing

//--- method 1: dp iteration
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int ones = 0, res = INT_MIN, now = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '1')
                ++ones;
            else
                now = min(ones, now+1);
        }
        return now;
    }
};