//--- Q: 1133. Largest Unique Number

//--- method 1: map
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int res = -1;
        unordered_map<int,int> map;
        for (auto &num: nums) {
            ++map[num];
        }
        for (auto &node: map) {
            if (node.second == 1) {
                res = max(res, node.first);
            }
        }
        return res;
    }
};

//--- method 2: bucket
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        vector<int> cnt(1001, 0);
        for (auto &num: nums) {
            ++cnt[num];
        }
        for (int i = 1000; i >= 1; --i) {
            if (cnt[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};