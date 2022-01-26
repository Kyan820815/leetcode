//--- Q: 1105. Filling Bookcase Shelves

//--- method 1: dp iteration
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, 0);
        for (int i = 0; i < n; ++i) {
            int curh = books[i][1], maxw = books[i][0], minh = curh+dp[i];
            for (int j = i-1; j >= 0 && maxw+books[j][0] <= shelfWidth; --j) {
                curh = max(curh, books[j][1]);
                minh = min(minh, curh+dp[j]);
                maxw += books[j][0];
            }
            dp[i+1] = minh;
        }
        return dp[n];
    }
};