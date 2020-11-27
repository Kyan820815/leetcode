//--- Q: 1257. Smallest Common Region

//--- method 1: build tree from bottom to top，better
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        for (int i = 0; i < regions.size(); ++i) {
            for (int j = 1; j < regions[i].size(); ++j) {
                parent[regions[i][j]] = regions[i][0];
            }
        }
        unordered_set<string> visit;
        while (region1 != "") {
            if (region1 == region2) {
                return region1;
            }
            visit.insert(region1);
            region1 = parent[region1];
        }
        while (region2 != "") {
            if (visit.find(region2) != visit.end()) {
                return region2;
            }
            region2 = parent[region2];
        }
        return "";
    }
};

//--- method 2: build tree from top to bottom
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < regions.size(); ++i) {
            for (int j = 1; j < regions[i].size(); ++j) {
                map[regions[i][0]].push_back(regions[i][j]);
            }
        }
        string start = regions[0][0];
        return postorder(start, region1, region2, map);
    }
    string postorder(string &now, string &r1, string &r2, unordered_map<string, vector<string>> &map) {
        if (now == r1 || now == r2) {
            return now;
        }
        int cnt = 0;
        string rtn = "";
        for (int i = 0; i < map[now].size(); ++i) {
            string val = postorder(map[now][i], r1, r2, map);
            if (val.size()) {
                rtn = val;
            }
            if (val == r1 || val == r2) {
                ++cnt;
            }
        }
        if (cnt == 2) {
            return now;
        } else {
            return rtn;
        }
    }
};
