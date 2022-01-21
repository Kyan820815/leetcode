//--- Q: 1086. High Five

//--- method 1: counting sort
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> id(1001), res;
        for (auto &item: items) {
            if (!id[item[0]].size()) {
                id[item[0]].resize(101, 0);
            }
            ++id[item[0]][item[1]];
        }
        for (int i = 1; i <= 1000; ++i) {
            if (!id[i].size()) {
                continue;
            }
            int sum = 0;
            for (int j = 100, cnt = 5; j >= 0 && cnt; --j) {
                while (id[i][j] && cnt) {
                    sum += j;
                    --cnt, --id[i][j];
                }
            }
            res.push_back({i,sum/5});
        }
        return res;
    }
};

//--- method 2: partial sort
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> id(1001), res;
        for (auto &item: items) {
            id[item[0]].push_back(item[1]);
        }
        for (int i = 1; i <= 1000; ++i) {
            if (!id[i].size()) {
                continue;
            }
            partial_sort(id[i].begin(), id[i].begin()+5, id[i].end(), greater<int>());
            int sum = 0;
            for (int j = 0; j < 5; ++j) {
                sum += id[i][j];
            }
            res.push_back({i,sum/5});
        }
        return res;
    }
};