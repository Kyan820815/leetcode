//--- Q: 0765. Couples Holding Hands

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), res = 0;
        for (int i = 0; i < n; i+=2) {
            parent.push_back(i);
            parent.push_back(i);
        }
        for (int i = 0; i < n; i+=2) {
            auto ap = findp(row[i]);
            auto bp = findp(row[i+1]);
            if (ap != bp) {
                parent[ap] = bp;
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