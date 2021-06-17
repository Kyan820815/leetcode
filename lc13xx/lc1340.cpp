//--- Q: 1340. Jump Game V

//--- method 1: dag + dfs
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> rel(n);
        vector<int> sk;
        for (int i = 0; i < n; ++i) {
            while (sk.size() && arr[sk.back()] < arr[i]) {
                if (i-sk.back() <= d) {
                    rel[i].push_back(sk.back());
                }
                sk.pop_back();
            }
            sk.push_back(i);
        }
        sk = {};
        for (int i = n-1; i >= 0; --i) {
            while (sk.size() && arr[sk.back()] < arr[i]) {
                if (sk.back()-i <= d) {
                    rel[i].push_back(sk.back());
                }
                sk.pop_back();
            }
            sk.push_back(i);
        }
        int maxv = 0;
        vector<int> dist(n, -1);
        for (int i = 0; i < n; ++i) {
            if (dist[i] == -1) {
                dfs(i, dist, rel);
            }
            maxv = max(maxv, dist[i]);
        }
        return maxv;
    }
    int dfs(int now, vector<int> &dist, vector<vector<int>> &rel) {
        if (!rel[now].size()) {
            return dist[now] = 1;
        }
        if (dist[now] != -1) {
            return dist[now];
        }
        int maxv = 0;
        for (auto &node: rel[now]) {
            maxv = max(maxv, dfs(node, dist, rel));
        }
        return dist[now] = maxv+1;
    }
};