//--- Q: 1079. Letter Tile Possibilities

//--- method 1: count if appear before
class Solution {
public:
    int res = 0;
    int numTilePossibilities(string tiles) {
        vector<int> used(tiles.size(), 0);
        sort(tiles.begin(), tiles.end());
        dfs(tiles, 0, used);
        return res;    
    }
    void dfs(string &tiles, int times, vector<int> &used) {
        if (times == tiles.size()) {
            return;
        }
        for (int i = 0; i < tiles.size(); ++i) {
            if (i && !used[i-1] && tiles[i] == tiles[i-1] || used[i]) {
                continue;
            }
            ++res;
            used[i] = 1;
            dfs(tiles, times+1, used);
            used[i] = 0;
        }
    }
};

//--- method 2: sort then compare with previous ch
class Solution {
public:
    int res = 0;
    int numTilePossibilities(string tiles) {
        vector<int> used(tiles.size(), 0);
        dfs(tiles, 0, used);
        return res;    
    }
    void dfs(string &tiles, int times, vector<int> &used) {
        if (times == tiles.size()) {
            return;
        }
        vector<int> cnt(26, 0);
        for (int i = 0; i < tiles.size(); ++i) {
            if (!cnt[tiles[i]-'A'] && !used[i]) {
                ++res;
                cnt[tiles[i]-'A'] = 1;
                used[i] = 1;
                dfs(tiles, times+1, used);
                used[i] = 0;
            }
        }
    }
};