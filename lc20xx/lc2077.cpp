//--- Q: 2077. Paths in Maze That Lead to Same Room

//--- method 1: set operation
class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<unordered_set<int>> rel(n);
        int res = 0;
        for (auto &edge: corridors) {
            rel[edge[0]-1].insert(edge[1]-1);
            rel[edge[1]-1].insert(edge[0]-1);
            for (auto &node: rel[edge[0]-1]) {
                if (rel[edge[1]-1].find(node) != rel[edge[1]-1].end()) {
                    ++res;
                }
            }
        }
        return res;
    }
};