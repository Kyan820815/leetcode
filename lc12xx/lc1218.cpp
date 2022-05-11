//--- Q: 1218. Longest Arithmetic Subsequence of Given Difference

//--- method 1: dp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> map;
        int res = 0;
        for (auto &val: arr) {
            map[val] = max(map[val], map[val-difference]+1);
            res = max(res, map[val]);
        }
        return res;
    }
};