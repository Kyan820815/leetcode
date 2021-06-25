//--- Q: 079. Word Search

//--- method 1: dfs without additional record array
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	int row = board.size(), col = board[0].size();
    	int go = 0;
    	bool find;

    	for (int i = 0; i < row; ++i)
    	{
    		for (int j = 0; j < col; ++j)
    		{
    			if (dfs(board, word, i, j, row, col, go))
    				return true;
    		}
    	}
    	return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int nR, int nC, int row, int col, int go)
    {
    	bool find = false;
    	if (board[nR][nC] != word[go]) return false;
    	if (go == word.size()-1) return true;

    	char curC = board[nR][nC];
    	board[nR][nC] = '*';
    	//--- top
    	if (!find && nR-1 >= 0 && board[nR-1][nC] != '*')
    		find = dfs(board, word, nR-1, nC, row, col, go+1);
    	//--- down
    	if (!find && nR+1 < row && board[nR+1][nC] != '*')
    		find = dfs(board, word, nR+1, nC, row, col, go+1);
    	//--- left
    	if (!find && nC-1 >= 0 && board[nR][nC-1] != '*')
    		find = dfs(board, word, nR, nC-1, row, col, go+1);
    	//--- right
    	if (!find && nC+1 < col && board[nR][nC+1] != '*')
    		find = dfs(board, word, nR, nC+1, row, col, go+1);
    	board[nR][nC] = curC;
    	return find;
    }
};

//--- method 2: used map to check if used
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	int row = board.size(), col = board[0].size();
    	vector<vector<int>> used(row, vector<int> (col,0));
    	int go = 0, find = 0;

    	for (int i = 0; i < row; ++i)
    	{
    		for (int j = 0; j < col; ++j)
    		{
    			if (board[i][j] == word[0])
    			{
    				dfs(board, word, used, i, j, row, col, go, find);
    				if (find) return true;
    			}
    		}
    	}
    	return false;

    }
    void dfs(vector<vector<char>> &board, string &word, vector<vector<int>> &used, int nR, int nC, int row, int col, int go, int &find)
    {
    	
    	if (board[nR][nC] != word[go]) return;
    	if (go == word.size()-1)
    	{
    		find = 1;
	    	return;
    	}
    	used[nR][nC] = 1;
    	//--- top
    	if (!find && nR-1 >= 0 && !used[nR-1][nC])
    		dfs(board, word, used, nR-1, nC, row, col, go+1, find);
    	//--- down
    	if (!find && nR+1 < row && !used[nR+1][nC])
    		dfs(board, word, used, nR+1, nC, row, col, go+1, find);
    	//--- left
    	if (!find && nC-1 >= 0 && !used[nR][nC-1])
    		dfs(board, word, used, nR, nC-1, row, col, go+1, find);
    	//--- right
    	if (!find && nC+1 < col && !used[nR][nC+1])
    		dfs(board, word, used, nR, nC+1, row, col, go+1, find);
    	used[nR][nC] = 0;
    }
};