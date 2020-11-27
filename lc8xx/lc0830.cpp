//--- Q: 830. Positions of Large Groups

//--- method 1: linear check
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int last = 0;
        for (int i = 1; i <= S.size(); ++i) {
            if (i == S.size() || S[i] != S[i-1]) {
                if (i-last >= 3) {
                    res.push_back({last, i-1});
                }
                last = i;
            }
        }
        return res;
    }
};