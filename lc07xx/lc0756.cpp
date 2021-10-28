//--- Q: 0756. Pyramid Transition Matrix

//--- method 1: dfs by index, not pass string
class Solution {
public:
    unordered_map<string, vector<char>> map;
    unordered_map<string, bool> visit;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &allow: allowed) {
            map[allow.substr(0,2)].push_back(allow[2]);
        }
        string next = "";
        return dfs(0, bottom, next);
    }
    bool dfs(int idx, string &cur, string &next) {
        if (visit.find(cur) != visit.end()) {
            return visit[cur];
        }
        if (cur.size() == 1) {
            return true;
        }
        if (idx == cur.size()-1) {
            string tmp = "";
            return dfs(0, next, tmp);
        }
        for (auto &ch: map[cur.substr(idx,2)]) {
            next.push_back(ch);
            if (dfs(idx+1, cur, next)) {
                return visit[cur] = true;
            }
            next.pop_back();
        }
        return visit[cur] = false;
    }
};