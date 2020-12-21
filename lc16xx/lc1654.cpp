//--- Q: 1654. Minimum Jumps to Reach Home

//--- method 1: bfs with state
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> not_allowed(forbidden.begin(), forbidden.end());
        vector<vector<int>> visit(2, vector<int>(6000, 0));
        queue<pair<int, bool>> que;
        visit[0][0] = visit[1][0] = 1;
        que.push({0, 0});
        int res = 0;
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                int cur = now.first, type = now.second;
                if (cur == x) {
                    return res;
                }
                if (cur+a < 6000 && !visit[0][cur+a] && not_allowed.find(cur+a) == not_allowed.end()) {
                    visit[0][cur+a] = 1;
                    que.push({cur+a, 0});
                }
                if (cur-b >= 0 && !type && !visit[1][cur-b] && not_allowed.find(cur-b) == not_allowed.end()) {
                    visit[1][cur-b] = 1;
                    que.push({cur-b, 1});
                }
            }
            ++res;
        }
        return -1;
    }
};