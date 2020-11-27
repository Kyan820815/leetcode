//--- Q: 1275. Find Winner on a Tic Tac Toe Game

//--- method 1: linear check
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = 3;
        vector<int> rows(n, 0), cols(n, 0);
        int first = 0, second = 0, dir = 0;
        for (int i = 0; i < moves.size(); ++i) {
            int diff = 1 + (i&1) * (-2);
            if (moves[i][0] == moves[i][1]) {
                first += diff;
            }
            if (moves[i][0] + moves[i][1] == n-1) {
                second += diff;
            }
            rows[moves[i][0]] += diff;
            cols[moves[i][1]] += diff;
            if (abs(rows[moves[i][0]]) == n || abs(cols[moves[i][1]]) == n
                || abs(first) == n || abs(second) == n) {
                return string(1, 'A' + i % 2);
            }
        }
        return moves.size() < n*n ? "Pending" : "Draw";
    }
};