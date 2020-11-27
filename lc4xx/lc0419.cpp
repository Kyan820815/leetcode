//--- Q: 419. Battleships in a Board

//--- method 1: O(1) space without modifying input
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0, row = board.size(), col = board[0].size();
        for (int i = 0; i < board.size(); ++i)
        {
        	for (int j = 0; j < board[i].size(); ++j)
        	{
        		if (board[i][j] == 'X'  && (i+1 == row || board[i+1][j] == '.')
        								&& (j+1 == col || board[i][j+1] == '.'))
        			res++;
        	}
        }
        return res;
    }
};

//--- method 2: dfs 
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i < board.size(); ++i)
        {
        	for (int j = 0; j < board[i].size(); ++j)
        	{
        		if (board[i][j] == 'X')
        		{
        			dfs(board, i, j);
        			res++;
        		}
        	}
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, int i, int j)
    {
    	int row = board.size(), col = board[0].size();
    	board[i][j] = '.';
    	if (i-1 >= 0 && board[i-1][j] == 'X')
    		dfs(board, i-1, j);
    	if (i+1 < row && board[i+1][j] == 'X')
    		dfs(board, i+1, j);
    	if (j-1 >= 0 && board[i][j-1] == 'X')
    		dfs(board, i, j-1);
    	if (j+1 < col && board[i][j+1] == 'X')
    		dfs(board, i, j+1);
    }
};