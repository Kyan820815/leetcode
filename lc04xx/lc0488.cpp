//--- Q: 0488. Zuma Game

//--- method 1: dfs with memorization
class Solution {
public:
    unordered_map<string, int> map;
    int findMinStep(string board, string hand) {
        vector<int> cnt(26, 0);
        for (auto &ch: hand) {
            ++cnt[ch-'A'];
        }
        map[""] = 0;
        auto res = dfs(board, cnt);
        return res == INT_MAX ? -1 : res;
    }
    int dfs(string &board, vector<int> &cnt) {
        board = remove(board);
        if (map.find(board) != map.end()) {
            return map[board];
        }
        int times = INT_MAX;
        for (int i = 0; i <= board.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                if (cnt[j]) {
                    --cnt[j];
                    string mid(1,j+'A');
                    string next = board.substr(0,i) + mid + board.substr(i);
                    auto rtn_cnt = dfs(next, cnt);
                    if (rtn_cnt != INT_MAX) {
                        times = min(times, rtn_cnt+1);
                    }
                    ++cnt[j];
                }
            }
        }
        return map[board] = times;
    }
    string remove(string &board) {
        for (int i = 1, j = 0; i <= board.size(); ++i) {
            if (i == board.size() || board[i] != board[j]) {
                if (i-j >= 3) {
                    string next = board.substr(0,j) + board.substr(i);
                    return remove(next);
                } else {
                    j = i;
                }
            }
        }
        return board;
    }
};