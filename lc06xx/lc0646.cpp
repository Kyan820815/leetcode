//--- Q: 0646. Maximum Length of Pair Chain

//--- method 1: O(nlogn) dp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int end = -1001, res = 0;
        for (auto &pair: pairs) {
            if (pair[0] > end) {
                ++res;
                end = pair[1];
            }
        }
        return res;
    }
};