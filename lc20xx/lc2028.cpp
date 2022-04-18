//--- Q: 2028. Find Missing Observations

//--- method 1: greedy
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res;
        int m = rolls.size();
        int msum = accumulate(rolls.begin(), rolls.end(), 0);
        int nsum = mean*(m+n)-msum; 
        if (n*6 < nsum || nsum < n) {
            return {};
        }
        for (int i = 1; i <= n; ++i) {
            int val = min(6, nsum-(n-i));
            nsum -= val;
            res.push_back(val);
        }
        return res;
    }
};