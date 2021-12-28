//--- Q: 0944. Delete Columns to Make Sorted

//--- method 1: brute force
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] < strs[j-1][i]) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};