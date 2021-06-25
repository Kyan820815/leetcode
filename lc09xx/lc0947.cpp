//--- Q: 947. Most Stones Removed with Same Row or Column

//--- method 1: union find
class Solution {
public:
    int island = 0;
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent;
        for (int i = 0; i < stones.size(); ++i) {
            int ap = findp(stones[i][0], parent);
            int bp = findp(~stones[i][1], parent);
            if (ap != bp) {
                parent[ap] = bp;
                --island;
            }
        }
        return stones.size() - island;
    }
    int findp(int now, unordered_map<int, int> &parent) {
        if (parent.find(now) == parent.end()) {
            parent[now] = now;
            ++island;
        } else if (parent[now] != now) {
            parent[now] = findp(parent[now], parent);
        }
        return parent[now];
    }
};

//--- method 2: dfs
class Solution {
public:
    vector<int> visitr, visitc;
    vector<vector<int>> relr, relc;
    Solution() {
        visitr.resize(10000, 0);
        visitc.resize(10000, 0);
        relr.resize(10000);
        relc.resize(10000);
    }
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < stones.size(); ++i) {
            relr[stones[i][0]].push_back(stones[i][1]);
            relc[stones[i][1]].push_back(stones[i][0]);
        }
        int island = 0;
        for (int i = 0; i < stones.size(); ++i) {
            if (!visitr[stones[i][0]]) {
                island++;
                visitr[stones[i][0]] = 1;
                dfsr(stones[i][0]);
                dfsc(stones[i][1]);
            }
        }
        return stones.size() - island;
    }
    void dfsr(int r) {
        for (int i = 0; i < relr[r].size(); ++i) {
            if (!visitc[relr[r][i]]) {
                visitc[relr[r][i]] = 1; 
                dfsc(relr[r][i]);
            }
        }
    }
    void dfsc(int c) {
        for (int i = 0; i < relc[c].size(); ++i) {
            if (!visitr[relc[c][i]]) {
                visitr[relc[c][i]] = 1;
                dfsr(relc[c][i]);
            }
        }

    }
};

//--- method 3: better version of method 2
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rel;
        unordered_map<int ,int> visit;
        int island = 0;
        for (int i = 0; i < stones.size(); ++i) {
            rel[stones[i][0]].push_back(~stones[i][1]);
            rel[~stones[i][1]].push_back(stones[i][0]);
        }
        for (int i = 0; i < stones.size(); ++i) {
            if (!visit[stones[i][0]]) {
                ++island;
                visit[stones[i][0]] = 1;
                dfs(stones[i][0], rel, visit);
            }
        }
        return stones.size() - island;
    }
    void dfs(int now, unordered_map<int, vector<int>> &rel, unordered_map<int, int>&visit) {
        for (int i = 0; i < rel[now].size(); ++i) {
            if (!visit[rel[now][i]]) {
                visit[rel[now][i]] = 1;
                dfs(rel[now][i], rel, visit);
            }
        }
    }
};