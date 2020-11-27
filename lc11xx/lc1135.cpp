//--- Q: 1135. Connecting Cities With Minimum Cost

//--- method 1: union find
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        int cnt = 1, res = 0;
        vector<int> p(N+1, 0);
        for (int i = 1; i <= N; ++i)
            p[i] = i;
        sort(connections.begin(), connections.end(), [](vector<int> &a, vector<int> &b)
         {
            return a[2] < b[2];
         });
        for (int i = 0; i < connections.size(); ++i)
        {
            int ap = findp(connections[i][0], p);
            int bp = findp(connections[i][1], p);
            if (ap == bp) continue;
            p[ap] = p[bp];
            cnt++;
            res += connections[i][2];
            if (cnt == N) return res;
        }
        return -1;
    }
    int findp(int i, vector<int> &parent)
    {
        while (i != parent[i])
            i = parent[i];
        return i;
    }
};

