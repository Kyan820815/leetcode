//--- Q: 0403. Frog Jump

//--- method 1: recursion with memorization using set
class Solution {
public:
    unordered_set<int> height;
    unordered_map<string, int> visit;
    bool canCross(vector<int>& stones) {
        for (auto &stone: stones) {
            height.insert(stone);
        }
        return dfs(0, 0, stones.back());
    }
    bool dfs(int k, int h, int last) {
        string tag = to_string(k) + "," + to_string(h);
        if (h == last) {
            return visit[tag] = 1;
        }
        if (visit.find(tag) != visit.end()) {
            return visit[tag];
        }
        for (int i = max(0, k-1); i <= k+1; ++i) {
            if (!i) {
                continue;
            }
            if (height.find(h+i) != height.end()) {
                if (dfs(i, h+i, last)) {
                    return visit[tag] = 1;
                }
            }
        }
        return visit[tag] = 0;
    }
};

//--- method 2: recursion with memorization using vector of vector
class Solution {
public:
    unordered_map<int, int> height;
    vector<vector<int>> visit;
    bool canCross(vector<int>& stones) {
        visit.resize(stones.size(), vector<int>(stones.size(), -1));
        for (int i = 0; i < stones.size(); ++i) {
            height[stones[i]] = i;
        }
        return dfs(0, 0, stones.back());
    }
    bool dfs(int k, int h, int last) {
        auto idx = height[h];
        if (h == last) {
            return visit[idx][k] = 1;
        }
        if (visit[idx][k] != -1) {
            return visit[idx][k];
        }
        for (int i = max(0, k-1); i <= k+1; ++i) {
            if (!i) {
                continue;
            }
            if (height.find(h+i) != height.end()) {
                if (dfs(i, h+i, last)) {
                    return visit[idx][k] = 1;
                }
            }
        }
        return visit[idx][k] = 0;
    }
};

//--- method 3: dp iteration
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][1] = 1;
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = stones[i]-stones[j];
                if (diff >= n) {
                    continue;
                }
                if (dp[j][diff]) {
                    if (diff+1 < n) {
                        dp[i][diff+1] = 1;
                    }
                    dp[i][diff] = 1;
                    if (diff > 1) {
                        dp[i][diff-1] = 1;
                    }
                    if (i == n-1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
