//--- Q: 403. Frog Jump

//--- method 1-1: recursion with memorization
class Solution {
public:
    vector<vector<int>> visit;
    unordered_map<int, int> pos;
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        visit.resize(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            pos[stones[i]] = i;
        }
        return dfs(0, 0, 0, n-1);
    }
    int dfs(int height, int k, int now, int end) {
        if (visit[now][k] != -1) {
            return visit[now][k];
        }
        if (pos[height] == end) {
            return visit[now][k] = 1;
        }
        for (int i = max(k-1,1); i <= k+1; ++i) {
            if (pos.find(height+i) != pos.end()) {
                if (dfs(height+i, i, pos[height+i], end)) {
                    return visit[now][k] = 1;
                }
            }
        }
        return visit[now][k] = 0;
    }
};

//--- method 1-2: another recursion with memorization
class Solution {
public:
    unordered_map<int, int> map;
    unordered_map<string, int> visit;
    bool canCross(vector<int>& stones) {
        for (int i = 0; i < stones.size(); ++i) {
            map[stones[i]] = i;
        }
        return dfs(0, 0, stones.size());
    }
    bool dfs(int k, int h, int n) {
        if (map[h] == n-1) {
            return true;
        }
        string tag = to_string(k)+"_"+to_string(h);
        if (visit.find(tag) != visit.end()) {
            return visit[tag];
        }
        for (int i = max(1, k-1); i <= k+1; ++i) {
            int nh = h+i;
            if (map.find(nh) != map.end()) {
                if (dfs(i, nh, n)) {
                    return visit[tag] = true;
                }
            }
        }
        return visit[tag] = false;
    }
};

//--- method 2: dp iteration
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][1] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = stones[i]-stones[j];
                if (diff >= n || !dp[j][diff]) {
                    continue;
                }
                dp[i][diff] = 1;
                if (diff < n-1) {
                    dp[i][diff+1] = 1;
                }
                if (diff > 0) {
                    dp[i][diff-1] = 1;
                }
                if (i == n-1) {
                    return true;
                }
            }
        }
        return false;
    }
};
