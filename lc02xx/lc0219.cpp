//--- Q: 0219. Contains Duplicate II

//--- method 1: hashmap
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) != map.end() && i-map[nums[i]] <= k) {
                return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};

//--- method 2: sliding window
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                set.erase(nums[i-k-1]);
            }
            if (set.find(nums[i]) != set.end()) {
                return true;
            }
            set.insert(nums[i]);
      }
        return false;
    }
};