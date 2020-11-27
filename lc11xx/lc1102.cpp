//--- Q: 1102. Path With Maximum Minimum Value

//--- method 1: Dijkstra
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int minval = INT_MAX;
        int row = A.size(), col = A[0].size();
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        auto comp = [](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
            return a.first < b.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> que(comp);
        que.push({A[0][0], {0, 0}});
        A[0][0] = -1;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int r = now.second.first, c = now.second.second;
            if (r == row-1 && c == col-1) {
                minval = now.first;
                break;
            }
            for (int i = 0; i < 4; ++i) {
                int nr = r+dir[i][0], nc = c+dir[i][1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || A[nr][nc] == -1)
                    continue;
                que.push({min(now.first, A[nr][nc]), {nr, nc}});
                A[nr][nc] = -1;
            }
        }
        return minval;
    }
};
