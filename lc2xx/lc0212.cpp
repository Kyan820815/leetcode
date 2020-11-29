//--- Q: 212. Word Search II

//--- method 1: trie tree + dfs
class Node {
public:
    Node() {
        end = false;
        next.resize(26, NULL);
    }
    bool end;
    vector<Node *> next;
};

class Trietree {
public:
    Trietree() {
        root = new Node();
    }
    void insert(string &word) {
        Node *now = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!now->next[word[i]-'a']) {
                now->next[word[i]-'a'] = new Node();
            }
            now = now->next[word[i]-'a'];
        }
        now->end = true;
    }
    
    Node *root;
};

class Solution {
public:
    vector<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        Trietree *trie = new Trietree();
        for (int i = 0; i < words.size(); ++i) {
            trie->insert(words[i]);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col && words.size() > res.size(); ++j) {
                string word = "";
                Node *now = trie->root;
                dfs(i, j, board, dir, now->next[board[i][j]-'a'], word);
            }
        }
        return res;
    }   
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &dir, Node *now, string &word) {
        int row = board.size(), col = board[0].size();
        if (!now) {
            return;
        }
        word.push_back(board[i][j]);
        if (now->end) {
            res.push_back(word);
            now->end = false;
        }
        char tmp = board[i][j];
        board[i][j] = '0';
        for (int k = 0; k < 4; ++k) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if (ni < 0 || ni >= row || nj < 0 || nj >= col || board[ni][nj] == '0') {
                continue;
            }
            dfs(ni, nj, board, dir, now->next[board[ni][nj]-'a'], word);
        }
        board[i][j] = tmp;
        word.pop_back();
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