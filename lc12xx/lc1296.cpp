//--- Q: 1296. Divide Array in Sets of K Consecutive Numbers

//--- method 1: unordered_map
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        sort(nums.begin(), nums.end());
        for (auto &num: nums) {
            ++map[num];
        }
        for (auto &num: nums) {
            if (!map[num]) {
                continue;
            }
            int cnt = map[num];
            for (int i = 0; i < k; ++i) {
                if (map[num+i]-cnt < 0) {
                    return false;
                }
                map[num+i] -= cnt;
            }
        }
        return true;
    }
};

//--- method 2: map
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> map;
        for (auto &num: nums) {
            ++map[num];
        }
        for (auto &num: map) {
            if (!num.second) {
                continue;
            }
            int cnt = num.second;
            for (int i = 0; i < k; ++i) {
                if (map[num.first+i]-cnt < 0) {
                    return false;
                }
                map[num.first+i] -= cnt;
            }
        }
        return true;
    }
};