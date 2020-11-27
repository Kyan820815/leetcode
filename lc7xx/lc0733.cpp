//--- Q: 733. Flood Fill

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int tagColor = image[sr][sc];
        if (tagColor == newColor) return image;
        dfs(image, sr, sc, newColor, tagColor);
        return image;
    }
    void dfs(vector<vector<int>> &image, int r, int c, int newColor, int tagColor)
    {
        int row = image.size(), col = image[0].size();
        image[r][c] = newColor;
        if (r-1 >= 0 && image[r-1][c] == tagColor)
            dfs(image, r-1, c, newColor, tagColor);
        if (c-1 >= 0 && image[r][c-1] == tagColor)
            dfs(image, r, c-1, newColor, tagColor);
        if (r+1 < row && image[r+1][c] == tagColor)
            dfs(image, r+1, c, newColor, tagColor);
        if (c+1 < col && image[r][c+1] == tagColor)
            dfs(image, r, c+1, newColor, tagColor);
    }
};