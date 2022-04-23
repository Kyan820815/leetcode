//--- Q: 2115. Find All Possible Recipes from Given Supplies

//--- method 1: naive processing
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<int>> map;
        unordered_map<int, unordered_set<string>> contain;
        int have = 1, n = recipes.size();
        vector<string> res;
        vector<int> idx;
        for (int i = 0; i < n; ++i) {
            idx.push_back(i);
            for (auto &ingredient: ingredients[i]) {
                map[ingredient].push_back(i);
            }
        }
        for (auto &supply: supplies) {
            for (auto &i: map[supply]) {
                contain[i].insert(supply);
            }
        }
        while (have) {
            have = 0;
            vector<int> nextidx;
            for (int i = 0; i < idx.size(); ++i) {
                if (contain[idx[i]].size() == ingredients[idx[i]].size()) {
                    have = 1;
                    res.push_back(recipes[idx[i]]);
                    for (auto &j: map[recipes[idx[i]]]) {
                        contain[j].insert(recipes[idx[i]]);
                    }
                } else {
                    nextidx.push_back(idx[i]);
                }
            }
            idx = nextidx;
        }
        return res;
    }
};

//--- method 2: bfs
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> set(supplies.begin(), supplies.end());
        unordered_map<string, vector<int>> rel;
        vector<int> deg(n, 0);
        for (int i = 0; i < n; ++i) {
            for (auto &ingredient: ingredients[i]) {
                if (set.find(ingredient) == set.end()) {
                    rel[ingredient].push_back(i);
                    ++deg[i];
                }
            }
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                que.push(i);
            }
        }
        vector<string> res;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                res.push_back(recipes[now]); 
                for (auto &next: rel[recipes[now]]) {
                    if (!--deg[next]) {
                        que.push(next);
                    }
                }
            }
        }
        return res;
    }
};