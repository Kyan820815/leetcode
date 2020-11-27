//--- Q: 1319. Number of Operations to Make Network Connected

//--- method 1: union find
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) {
            return -1;
        }
        vector<int> parent(n, -1);
        for (int i = 0; i < connections.size(); ++i) {
            int ap = findp(connections[i][0], parent);
            int bp = findp(connections[i][1], parent);
            if (ap != bp) {
                parent[ap] = bp;
                n--;
            }
        }
        return n-1;
    }
    int findp(int now, vector<int> &parent) {
        if (now != parent[now]) {
            return parent[now] = (parent[now] == -1) ? now : findp(parent[now], parent);
        }
        return now;
    }
};