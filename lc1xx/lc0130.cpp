//--- Q: 130. Surrounded Regions

//--- method 1: dfs
class Solution {
public:
    void solve(vector<vector<char>>& board) {
    	int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < col; ++j)
        	{
        		if ((i == 0 || j == 0 || i == row-1 || j == col-1) && board[i][j] == 'O')
        			dfs(board, i, j);
        	}
        }
        for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < col; ++j)
        	{
        		if (board[i][j] == 'Z')
        			board[i][j] = 'O';
        		else if (board[i][j] == 'O')
        			board[i][j] = 'X';
        	}
        }
    }
    void dfs(vector<vector<char>> &board, int r, int c)
    {
    	int row = board.size(), col = board[0].size();
    	board[r][c] = 'Z';
    	if (r-1 > 0 && board[r-1][c] == 'O')
    		dfs(board, r-1, c);
    	if (r+1 < row && board[r+1][c] == 'O')
    		dfs(board, r+1, c);
    	if (c-1 > 0 && board[r][c-1] == 'O')
    		dfs(board, r, c-1);
    	if (c+1 < col && board[r][c+1] == 'O')
    		dfs(board, r, c+1);
    }
};