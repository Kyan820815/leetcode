//--- Q: 0947. Most Stones Removed with Same Row or Column

//--- method 1: union find
class Solution {
public:
    unordered_map<int,int> parent;
    int group = 0;
    int removeStones(vector<vector<int>>& stones) {
        int cnt = stones.size();
        for (auto &stone: stones) {
            int ap = findp(stone[0]);
            int bp = findp(~stone[1]);
            if (ap != bp) {
                parent[ap] = bp;
                --group;
            }
        }
        return stones.size()-group;
    }
    int findp(int now) {
        if (parent.find(now) == parent.end()) {
            ++group;
            return parent[now] = now;
        } else if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};

//--- method 2: dfs
class Solution {
public:
    unordered_map<int, vector<int>> rel;
    unordered_set<int> visit;
    int removeStones(vector<vector<int>>& stones) {
        for (auto &stone: stones) {
            rel[stone[0]].push_back(~stone[1]);
            rel[~stone[1]].push_back(stone[0]);
        }
        int island = 0;
        for (auto &stone: stones) {
            if (visit.find(stone[0]) == visit.end()) {
                ++island;
                dfs(stone[0]);
            }
        }
        return stones.size() - island;
    }
    void dfs(int now) {
        visit.insert(now);
        for (auto &next: rel[now]) {
            if (visit.find(next) == visit.end()) {
                dfs(next);
            }
        }
    }
};