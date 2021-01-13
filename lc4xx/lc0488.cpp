//--- Q: 488. Zuma Game

//--- method 1: dfs with memorization
class Solution {
public:
    vector<int> cnt;
    unordered_map<string, int> map;
    int findMinStep(string board, string hand) {
        cnt.resize(26, 0);
        for (int i = 0; i < hand.size(); ++i) {
            ++cnt[hand[i]-'A'];
        }
        map["#"] = 0;
        board.push_back('#');
        int res = dfs(board);
        return res == 6 ? -1 : res;
    }
    int dfs(string &s) {
        if (map.find(s) != map.end()) {
            return map[s];
        }
        string now_str = remove(s);
        if (map.find(now_str) != map.end()) {
            return map[now_str];
        }
        int mincnt = 6;
        for (int i = 0; i < now_str.size()-1; ++i) {
            for (int j = 0; j < 26; ++j) {
                int times = cnt[j];
                if (cnt[j] > 0) {
                    char ch = 'A'+j;
                    string next = now_str.substr(0, i) + ch + now_str.substr(i);
                    --cnt[j];
                    mincnt = min(mincnt, 1+dfs(next));
                    ++cnt[j];
                }
            }
        }
        return map[now_str] = mincnt;
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