//--- Q: 1791. Find Center of Star Graph

//--- method 1: find hint in the problem
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};

//--- method 2: bfs
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        if (n == 1) {
            return 1;
        }
        vector<vector<int>> rel(n);
        vector<int> deg(n, 0);
        for (auto &edge: edges) {
            rel[edge[0]-1].push_back(edge[1]-1);
            rel[edge[1]-1].push_back(edge[0]-1);
            ++deg[edge[0]-1];
            ++deg[edge[1]-1];
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                que.push(i);
            }
        }
        while (n > 1) {
            auto qsize = que.size();
            n -= qsize;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &next: rel[now]) {
                    if (--deg[next] == 1) {
                        que.push(next);
                    }
                }
            }
        }
        return que.front()+1;
    }
};