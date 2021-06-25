//--- Q: 532. K-diff Pairs in an Array

//--- method 1: use map to process num+k and num-k
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> map;
        if (k < 0) {
            return 0;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) {
                if (map.find(nums[i]+k) != map.end()) {
                    ++res;
                }
                if (map.find(nums[i]-k) != map.end()) {
                    ++res;
                }
            } else {
                if (!k && map[nums[i]] == 1) {
                    ++res;
                }
            }
            ++map[nums[i]];
        }
        return res;
    }
};

//--- method 2: easy understood and two pass
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++map[nums[i]];
        }
        for (auto &m: map) {
            if (!k && m.second > 1 || k && map.find(m.first+k) != map.end()) {
                ++res;
            }
        }
        return res;
    }
};