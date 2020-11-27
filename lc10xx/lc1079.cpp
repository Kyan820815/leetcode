//--- Q: 1079. Letter Tile Possibilities

//--- method 1: dfs recursion
class Solution {
public:
    int numTilePossibilities(string tiles) {
        int res = 0;
        sort(tiles.begin(), tiles.end());
        vector<bool> visit(tiles.size(), false);
        dfs(0, tiles, res, visit);
        return res;
    }
    void dfs(int cnt, string &tiles, int &res, vector<bool> &visit) {
        if (cnt == tiles.size())
            return;
        for (int i = 0; i < tiles.size(); ++i) {
            if (i > 0 && tiles[i] == tiles[i-1] && !visit[i-1] || visit[i])
                continue;
            visit[i] = true;
            ++res;
            dfs(cnt+1, tiles, res, visit);
            visit[i] = false;
        }
    }
};

//--- method 1-2: ABA case
class Solution {
public:
    int res = 0;
    int numTilePossibilities(string tiles) {
        tiles = "ABA";
        vector<int> previous_visit(tiles.size(), 0);
        dfs(previous_visit, tiles);
        return res;
    }
    void dfs(vector<int> &previous_visit, string &S) {
        vector<int> cur_level_visit(26, 0);
        for (int i = 0; i < S.size(); ++i) {
            if (previous_visit[i] || cur_level_visit[S[i]-'A']) {
                continue;
            }
            ++res;
            previous_visit[i] = cur_level_visit[S[i]-'A'] = 1;
            dfs(previous_visit, S);
            previous_visit[i] = 0;
        }
    }
};