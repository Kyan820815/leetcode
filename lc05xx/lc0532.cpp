//--- Q: 0532. K-diff Pairs in an Array

//--- method 1: use map to process num+k and num-k
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int res = 0;
        for (auto &num: nums) {
            if (!k && map[num] == 1) {
                ++res;
            } else if (k && map.find(num) == map.end()) {
                if (map.find(num-k) != map.end()) {
                    ++res;
                }
                if (map.find(num+k) != map.end()) {
                    ++res;
                }
            }
            ++map[num];
        }
        return res;
    }
};

//--- follow up:
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int res = 0;
        for (auto &num: nums) {
            if (!k) {
                res += map[num];
            } else {
                res += map[num-k] + map[num+k];
            }
            ++map[num];
        }
        return res;
    }
};