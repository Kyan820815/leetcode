//--- Q: 212. Word Search II

//--- method 1: trie tree + dfs
class Node {
public:
    Node() {
        next.resize(26, NULL);
        isWord = false;
    }
    vector<Node *> next;
    bool isWord;
};
class TrieTree {
public:
    TrieTree() {
        root = new Node;
    }
    void insert(string &word) {
        Node *now = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!now->next[word[i] - 'a'])
                now->next[word[i] - 'a'] = new Node();
            now = now->next[word[i] - 'a'];
        }
        now->isWord = true;
    }
Node *root;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        unordered_set<string> res;
        int row = board.size(), col = board[0].size();
        TrieTree *tree = new TrieTree();
        for (int i = 0; i < words.size(); ++i)
            tree->insert(words[i]);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                string nowstr = "";
                char tmp = board[i][j];
                board[i][j] = '0';
                nowstr.push_back(tmp);
                dfs(i, j, board, dir, res, tree->root->next[tmp-'a'], nowstr);
                board[i][j] = tmp;
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    void dfs(int r, int c, vector<vector<char>> &board, vector<vector<int>> &dir, unordered_set<string> &res, Node *now, string &nowstr) {
        int row = board.size(), col = board[0].size();
        if (!now)
            return;
        if (now->isWord)
            res.insert(nowstr);
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || board[nr][nc] == '0')
                continue;
            char tmp = board[nr][nc];
            board[nr][nc] = '0';
            nowstr.push_back(tmp);
            dfs(nr, nc, board, dir, res, now->next[tmp-'a'], nowstr);
            nowstr.pop_back();
            board[nr][nc] = tmp;
        }
    }
};