//--- Q: 1135. Connecting Cities With Minimum Cost

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });
        parent.resize(n, -1);
        int res = 0;
        for (auto &connection: connections) {
            int ap = findp(connection[0]-1);
            int bp = findp(connection[1]-1);
            if (ap != bp) {
                parent[ap] = bp;
                res += connection[2];
                if (--n == 1) {
                    return res;
                }
            }
        }
        return -1;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};

//--- method 2: union find with union by size
class Solution {
public:
    vector<int> parent;
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });
        parent.resize(n, -1);
        int res = 0;
        for (auto &connection: connections) {
            int ap = findp(connection[0]-1);
            int bp = findp(connection[1]-1);
            if (ap != bp) {
                if (-parent[ap] < -parent[bp]) {
                    swap(ap, bp);
                }
                parent[ap] += parent[bp];
                parent[bp] = ap;
                res += connection[2];
                if (parent[ap] == -n) {
                    return res;
                }
            }
        }
        return -1;
    }
    int findp(int now) {
        return parent[now] < 0 ? now : parent[now] = findp(parent[now]);
    }
};

