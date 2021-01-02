//--- Q: 488. Zuma Game

//--- method 1: dfs with memorization
class Solution {
public:
    vector<int> cnt;
    unordered_map<string, int> map;
    int findMinStep(string board, string hand) {
        cnt.resize(26, 0);
        board.push_back('#');
        for (int i = 0; i < hand.size(); ++i) {
            ++cnt[hand[i]-'A'];
        }
        map["#"] = 0;
        int res = dfs(board);
        return res == 6 ? -1 : res;
    }
    int dfs(string &s) {
        int maxcnt = 6;
        if (map.find(s) != map.end()) {
            return map[s];
        }
        string next = remove(s);
        if (map.find(next) != map.end()) {
            return map[s] = map[next];
        }
        for (int i = 0; i < next.size()-1; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (cnt[k] > 0) {
                    --cnt[k];
                    char ch = k+'A';
                    string cur;
                    cur = ch + s.substr(i);
                    if (i) {
                        cur = s.substr(0, i) + cur;
                    }
                    maxcnt = min(maxcnt, 1+dfs(cur));
                    ++cnt[k];
                }
            }
        }
        return map[s] = maxcnt;
    }
    string remove(string &s) {
        for (int i = 1, j = 0; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                continue;
            }
            if (i-j >= 3) {
                string next = s.substr(0, j) + s.substr(i);
                return remove(next);
            } else {
                j = i;
            }
        }
        return s;
    }
};