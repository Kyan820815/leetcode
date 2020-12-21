//--- Q: 332. Reconstruct Itinerary

//--- method 1: iterative
class Solution {
public:
    unordered_map<string, multiset<string>> map;
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); ++i) {
            map[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> sk = {"JFK"};
        while (sk.size()) {
            string now = sk.back();
            if (!map[now].size()) {
                res.push_back(now);
                sk.pop_back();
            } else {
                string first = *map[now].begin();
                map[now].erase(map[now].begin());
                sk.push_back(first);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//--- method 2: recursion
class Solution {
public:
    unordered_map<string, multiset<string>> map;
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); ++i) {
            map[tickets[i][0]].insert(tickets[i][1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(string now) {
        while (map[now].size()) {
            string first = *map[now].begin();
            map[now].erase(map[now].begin());
            dfs(first);
        }
        res.push_back(now);
    }
};
