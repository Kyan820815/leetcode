//--- Q: 756. Pyramid Transition Matrix

//--- method 1: dfs by index, not pass string
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> map;
        string next = "";
        for (int i = 0; i < allowed.size(); ++i) {
            map[allowed[i].substr(0,2)].push_back(allowed[i][2]);
        }
        return dfs(0, map, next, bottom);
    }
    bool dfs(int start, unordered_map<string, vector<char>> &map, string &next, string &now) {
        if (now.size() == 1) {
            return true;
        }
        if (start == now.size()-1) {
            string empty = "";
            return dfs(0, map, empty, next);
        }
        string nowstr = now.substr(start, 2);
        for (int i = 0; i < map[nowstr].size(); ++i) {
            next.push_back(map[nowstr][i]);
            if (dfs(start+1, map, next, now)) {
                return true;
            }
            next.pop_back();
        }
        return false;
    }
};

//--- method 2: dfs
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> map;
        for (int i = 0; i < allowed.size(); ++i) {
            map[allowed[i].substr(0,2)].push_back(allowed[i][2]);
        }
        return dfs(bottom, map);
    }
    int dfs(string &now, unordered_map<string, vector<char>> &map) {
        if (now.size() == 1) {
            return 1;
        }
        vector<string> nowlist = getlist(0, now, map);
        for (int i = 0; i < nowlist.size(); ++i) {
            if (nowlist[i].size() == now.size()-1 && dfs(nowlist[i], map)) {
                return 1;
            }
        }
        return 0;
    }
    vector<string> getlist(int idx, string &now, unordered_map<string, vector<char>> &map) {
        if (idx == now.size()-1) {
            return {};
        }
        vector<string> res, next = getlist(idx+1, now, map);
        string nowstr = now.substr(idx, 2);
        for (int i = 0; i < map[nowstr].size(); ++i) {
            res.push_back(string(1, map[nowstr][i]));
            int last = res.size()-1;
            for (int j = 0; j < next.size(); ++j) {
                res.push_back(res[last] + next[j]);
            }
        }
        return res;
    }
};
