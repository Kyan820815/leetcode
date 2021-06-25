//--- Q: 909. Snakes and Ladders

//--- method 1: save index and its location in the board
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> que;
        unordered_map<int, pair<int, int>> map;
        unordered_set<int> visit;
        int steps = 0, row = board.size(), col = board[0].size(), r = row-1, c = 0, dir = 1;
        for (int i = 0; i < row*col; ++i) {
            map[i+1] = {r,c};
            c += dir;
            if (c == col || c < 0) {
                c = (c < 0) ? 0 : col-1;
                dir *= -1;
                --r;
            }
        }
        que.push(1);
        visit.insert(1), visit.insert(-1);
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                if (now == row*col) {
                    return steps;
                }
                que.pop();
                for (int j = 1; j <= 6 && now <= row*col; ++j) {
                    int next = now+j;
                    if (visit.find(next) == visit.end()) {
                        visit.insert(next);
                        int nr = map[next].first, nc = map[next].second;
                        if (visit.find(board[nr][nc]) == visit.end()) {
                            que.push(board[nr][nc]);
                        } else if (board[nr][nc] == -1) {
                            que.push(next);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};

//--- method 2: turn to 1d array
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> que;
        unordered_set<int> visit;
        vector<int> board1d;
        int steps = 0, row = board.size(), col = board[0].size(), r = row-1, c = 0, dir = 1;
        for (int i = 0; i < row*col; ++i) {
            board1d.push_back(board[r][c]);
            c += dir;
            if (c == col || c < 0) {
                c = (c < 0) ? 0 : col-1;
                dir *= -1;
                --r;
            }
        }
        que.push(1);
        visit.insert(1), visit.insert(-1);
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                if (now == row*col) {
                    return steps;
                }
                que.pop();
                for (int j = 1; j <= 6 && now+j <= row*col; ++j) {
                    int next = now+j;
                    if (visit.find(next) == visit.end()) {
                        visit.insert(next);
                        if (visit.find(board1d[next-1]) == visit.end()) {
                            que.push(board1d[next-1]);
                        } else if (board1d[next-1] == -1) {
                            que.push(next);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};

//--- method 3: directly transfer
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        queue<int> que;
        que.push(1);
        unordered_set<int> visit;
        visit.insert(1);
        int res = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (now == row*col) {
                    return res;
                }
                for (int i = 1; i <= 6 && now+i <= row*col; ++i) {
                    int next = now+i;
                    int nr = row-(next-1)/col-1, nc = (next-1)%col;
                    if (nr%2 == row%2) {
                        nc = col-nc-1;
                    }
                    if (visit.find(next) == visit.end()) {
                        visit.insert(next);
                        if (board[nr][nc] != -1 && visit.find(board[nr][nc]) == visit.end()) {
                            que.push(board[nr][nc]);
                        } else if (board[nr][nc] == -1) {
                            que.push(next);
                        }
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};