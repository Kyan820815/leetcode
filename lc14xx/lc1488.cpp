//--- Q: 1488. Avoid Flood in The City

//--- method 1: min heap with set
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, vector<int>> map;
        unordered_set<int> cnt;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (rains[i]) {
                map[rains[i]].push_back(i);
            }
        }
        int minday = 1;
        auto comp = [](const array<int,2> &a, const array<int,2> &b) {
            return a[1] > b[1];
        };
        priority_queue<array<int,2>, vector<array<int,2>>, decltype(comp)> que(comp);
        for (int i = 0; i < n; ++i) {
            if (rains[i]) {
                if (cnt.find(rains[i]) != cnt.end()) {
                    return vector<int>{};
                }
                cnt.insert(rains[i]);
                auto pos = upper_bound(map[rains[i]].begin(), map[rains[i]].end(), i);
                if (pos == map[rains[i]].end()) {
                    que.push({rains[i], n});
                } else {
                    que.push({rains[i], *pos});
                }
                res.push_back(-1);
            } else {
                if (que.size()) {
                    auto now = que.top();
                    que.pop();
                    minday = now[0];
                    cnt.erase(minday);
                }
                res.push_back(minday);
                minday = 1;
            }
        }
        return res;        
    }
};

//--- method 2: map with set
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> lake;
        set<int> dry;

        vector<int> res(n,1);
        for (int i = 0; i < n; ++i) {
            if (rains[i]) {
                if (lake.find(rains[i]) != lake.end()) {
                    int day = lake[rains[i]];
                    auto pos = dry.upper_bound(day);
                    if (pos == dry.end()) {
                        return vector<int> {};
                    }
                    res[*pos] = rains[i];
                    dry.erase(pos);
                }
                lake[rains[i]] = i;
                res[i] = -1;
            } else {
                dry.insert(i);
            }
        }
        return res;        
    }
};