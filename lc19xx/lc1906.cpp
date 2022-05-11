//--- Q: 1906. Minimum Absolute Difference Queries

//--- method 1: binary search
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> set(101);
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            set[nums[i]].push_back(i);
        }
        for (auto &query: queries) {
            int last = -1, minv = INT_MAX;
            for (int i = 1; i <= 100; ++i) {
                if (!set[i].size()) {
                    continue;
                }
                auto pos = lower_bound(set[i].begin(), set[i].end(), query[0]);
                if (pos != set[i].end() && *pos <= query[1]) {
                    if (last != -1) {
                        minv = min(minv, i-last);
                    }
                    last = i;
                }
            }
            res.push_back(minv == INT_MAX ? -1 : minv);
        }
        return res;
    }
};

//--- method 2: prefix sum
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> set(nums.size()+1, vector<int>(101));
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i) {
                set[i+1] = set[i];
            }
            ++set[i+1][nums[i]];
        }
        for (auto &query: queries) {
            int last = -1, minv = INT_MAX;
            for (int i = 1; i <= 100; ++i) {
                if (set[query[1]+1][i] - set[query[0]][i]) {
                    if (last != -1) {
                        minv = min(minv, i-last);
                    }
                    last = i;
                }
            }
            res.push_back(minv == INT_MAX ? -1 : minv);
        }
        return res;
    }
};