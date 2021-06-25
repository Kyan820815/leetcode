//--- Q: 289. Game of Life

//--- method 1: finite state machine with 4 states
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
    	int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < col; ++j)
        	{
        		int cnt = 0;
        		for (int k = 0; k < 8; ++k)
        		{
        			int x = i+dir[k][0], y = j+dir[k][1];
        			if (x >= 0 && x < row && y >= 0 && y < col)
        			{
        				if (board[x][y] == 1 || board[x][y] == 3)
        					cnt++;
        			}
        		}
        		if (board[i][j] == 1 && (cnt < 2 || cnt > 3))
        			board[i][j] = 1;
        		else if (board[i][j] == 0 && cnt == 3)
        			board[i][j] = 2;
        		else if (board[i][j] == 1)
        			board[i][j] = 3;
        	}
        }
        for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < col; ++j)
        	{
        		board[i][j] >> 1;
        	}
        }
    }
};