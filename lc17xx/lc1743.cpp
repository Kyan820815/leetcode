//--- Q: 1743. Restore the Array From Adjacent Pairs

//--- method 1: adjacent list
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> map;
        for (auto &p: adjacentPairs) {
            map[p[0]].push_back(p[1]);
            map[p[1]].push_back(p[0]);
        }
        vector<int> res;
        int cur, pre;
        for (auto &[node, next]: map) {
            if (next.size() == 1) {
                res.push_back(node);
                res.push_back(next[0]);
                cur = next[0], pre = node;
                break;
            }
        }
        while (map[cur].size() != 1) {
            int next = map[cur][0] != pre ? map[cur][0] : map[cur][1];
            res.push_back(next);
            pre = cur;
            cur = next;
        }
        return res;
    }
};