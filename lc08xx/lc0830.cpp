//--- Q: 0830. Positions of Large Groups

//--- method 1: linear check
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int last = 0;
        vector<vector<int>> res;
        for (int i = 1; i <= s.size(); ++i) {
            if (i == s.size() || s[i] != s[last]) {
                if (i-last >= 3) {
                    res.push_back({last,i-1});
                }
                last = i;
            }
        }
        return res;
    }
};