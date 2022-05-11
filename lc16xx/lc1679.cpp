//--- Q: 1679. Max Number of K-Sum Pairs

//--- method 1: sort and two pointers
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1, res = 0;
        while (left < right) {
            if (nums[left]+nums[right] < k) {
                ++left;
            } else if (nums[left]+nums[right] > k) {
                --right;
            } else {
                ++left, --right, ++res;
            }
        }
        return res;
    }
};

//--- method 2: map
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int res = 0;
        for (auto &num: nums) {
            if (map.find(k-num) != map.end() && map[k-num]) {
                ++res;
                --map[k-num];
            } else {
                ++map[num];
            }
        }
        return res;
    }
};