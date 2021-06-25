//--- Q: 765. Couples Holding Hands

//--- method 1: union find
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> parent(row.size());
        int cnt = 0;
        for (int i = 0; i < row.size(); i+=2) {
            parent[i] = parent[i+1] = i;
        }
        for (int i = 0; i < row.size(); i+=2) {
            int ap = findP(row[i], parent);
            int bp = findP(row[i+1], parent);
            if (ap != bp) {
                parent[ap] = bp;
                ++cnt;
            }
        }
        return cnt;
    }
    int findP(int now, vector<int> &parent) {
        while (now != parent[now])
            now = parent[now];
        return now;
    }
}; 