//--- Q: 1462. Course Schedule IV

//--- method 1: dfs recursion
class Solution {
public:
    vector<vector<int>> rel, map;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        rel.resize(numCourses);
        map.resize(numCourses, vector<int>(numCourses, -1));
        for (auto &prerequisity: prerequisites) {
            rel[prerequisity[0]].push_back(prerequisity[1]);
            map[prerequisity[0]][prerequisity[1]] = 1;
        }
        vector<bool> res;
        for (auto &query: queries) {
            res.push_back(dfs(query[0], query[1]));
        }
        return res;
    }
    int dfs(int now, int end) {
        if (map[now][end] != -1) {
            return map[now][end];
        }
        for (auto &next: rel[now]) {
            if (dfs(next, end)) {
                return map[now][end] = 1;
            }
        }
        return map[now][end] = 0;
    }
};