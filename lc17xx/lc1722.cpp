//--- Q: 1722. Minimize Hamming Distance After Swap Operations

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), res = 0;
        parent.resize(n, -1);
        for (auto &edge: allowedSwaps) {
            int ap = findp(edge[0]);
            int bp = findp(edge[1]);
            if (ap != bp) {
                parent[ap] = bp;
            }
        }
        vector<unordered_multiset<int>> set(n);
        for (int i = 0; i < n; ++i) {
            set[findp(i)].insert(source[i]);
        }
        for (int i = 0; i < n; ++i) {
            auto it = set[findp(i)].find(target[i]);
            if (it != set[findp(i)].end()) {
                set[findp(i)].erase(it);
            } else {
                ++res;
            }
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};