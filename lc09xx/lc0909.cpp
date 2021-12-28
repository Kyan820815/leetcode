//--- Q: 0909. Snakes and Ladders

//--- method 1: transfer 1d index to r and c
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size(), res = 0;
        queue<int> que;
        que.push(1);
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                int cidx = que.front();
                que.pop();
                if (cidx == row*col) {
                    return res;
                }
                int last = min(cidx+6, row*col);
                for (int nidx = cidx+1; nidx <= last; ++nidx) {
                    int nr = row-(nidx-1)/col-1;
                    int nc = (((nidx-1)/col)&1) ? col-(nidx-1)%col-1 : (nidx-1)%col;
                    if (!board[nr][nc]) {
                        continue;
                    }
                    if (board[nr][nc] == -1) {
                        que.push(nidx);
                    } else {
                        que.push(board[nr][nc]);
                    }
                    board[nr][nc] = 0;
                }
            }
            ++res;
        }
        return -1;
    }
};