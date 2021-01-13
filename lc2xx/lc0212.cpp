//--- Q: 212. Word Search II

//--- method 1: trie tree + dfs
class TNode {
public:
    TNode () {
        next.resize(26, NULL);
        isend = false;
    }
    vector<TNode *> next;
    bool isend;
};
class TrieTree {
public:
    TrieTree() {
        root = new TNode();
    }
    void insert(string &str) {
        TNode *now = root;
        for (int i = 0; i < str.size(); ++i) {
            if (!now->next[str[i]-'a']) {
                now->next[str[i]-'a'] = new TNode();
            }
            now = now->next[str[i]-'a'];
        }
        now->isend = true;
    }
    TNode *root;
};
class Solution {
public:
    int row, col;
    vector<string> res;
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size(), col = board[0].size();
        TrieTree *trie = new TrieTree();
        for (int i = 0; i < words.size(); ++i) {
            trie->insert(words[i]);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (trie->root->next[board[i][j]-'a']) {
                    string str = "";
                    dfs(i, j, trie->root->next[board[i][j]-'a'], str, board);
                }
            }
        }
        return res;
    }
    void dfs(int r, int c, TNode *root, string &str, vector<vector<char>> &board) {
        str.push_back(board[r][c]);
        if (root->isend) {
            res.push_back(str);
            root->isend = false;
        }
        char old = board[r][c];
        board[r][c] = '#';
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || board[nr][nc] == '#' || !root->next[board[nr][nc]-'a']) {
                continue;
            }
            dfs(nr, nc, root->next[board[nr][nc]-'a'], str, board);
        }
        board[r][c] = old;
        str.pop_back();
    }
};

//--- method 2: simple dfs with word lenth restriction
class Solution {
public:
    int row, col;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size(), col = board[0].size();
        vector<string> res;
        for (int i = 0; i < words.size(); ++i) {
            if (exist(words[i], board)) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
    bool exist(string &word, vector<vector<char>> &board) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(i, j, 0, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    bool dfs(int r, int c, int idx, string &word, vector<vector<char>> &board) {
        if (board[r][c] != word[idx]) {
            return false;
        }
        if (idx+1 == word.size()) {
            return true;
        }
        char prev = board[r][c];
        board[r][c] = '0';
        bool find = false;
        for (int i = 0; i < 4; ++i) {
            int nr = dir[i][0] + r;
            int nc = dir[i][1] + c;
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || board[nr][nc] == '0') {
                continue;
            }
            find |= dfs(nr, nc, idx+1, word, board);
            if (find) {
                break;
            }
        }
        board[r][c] = prev;
        return find;
    }
};