//--- Q: 0212. Word Search II

//--- method 1: trie tree + dfs
class TNode {
public:
    TNode () {
        isend = false;
        next.resize(26, nullptr);
    }
    bool isend;
    vector<TNode *> next;
};
class Solution {
public:
    int row, col;
    vector<string> res;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TNode();
        for (auto &word: words) {
            insert(word);
        }
        row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                string str = "";
                dfs(i, j, root->next[board[i][j]-'a'], str, board);
            }
        }
        return res;
    }
    void dfs(int r, int c, TNode *now, string &str, vector<vector<char>> &board) {
        if (!now) {
            return;
        }
        str.push_back(board[r][c]);
        if (now->isend) {
            now->isend = false;
            res.push_back(str);
        }
        auto tmp = board[r][c];
        board[r][c] = '.';
        for (auto &dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || board[nr][nc] == '.') {
                continue;
            }
            dfs(nr, nc, now->next[board[nr][nc]-'a'], str, board);
        }
        str.pop_back();
        board[r][c] = tmp;
    }
    void insert(string &str) {
        auto now = root;
        for (auto &ch: str) {
            if (!now->next[ch-'a']) {
                now->next[ch-'a'] = new TNode();
            }
            now = now->next[ch-'a'];
        }
        now->isend = true;
    }
    TNode *root;
};