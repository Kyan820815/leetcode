//--- Q: 1640. Check Array Formation Through Concatenation

//--- method 1: count first element of each piece
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> cnt(101, -1);
        for (int i = 0; i < pieces.size(); ++i) {
            cnt[pieces[i][0]] = i;
        }
        for (int i = 0; i < arr.size();) {
            int type = cnt[arr[i]];
            if (cnt[arr[i]] == -1) {
                return false;
            }
            for (int j = 0; j < pieces[type].size(); ++j,++i) {
                if (arr[i] != pieces[type][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};