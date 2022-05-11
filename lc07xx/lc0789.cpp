//--- Q: 0789. Escape The Ghosts

//--- method 1: count distance
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = INT_MAX;
        for (auto &ghost: ghosts) {
            dis = min(dis, abs(target[0]-ghost[0])+abs(target[1]-ghost[1]));
        }
        return abs(target[0])+abs(target[1]) < dis;
    }
};