//--- Q: 1105. Filling Bookcase Shelves

//--- method 1: dp iteration
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i, h = 0, w = 0; j > 0 && w + books[j-1][0] <= shelf_width; --j) {
                w += books[j-1][0];
                h = max(h, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + h);
            }
        }
        return dp.back();
    }
};