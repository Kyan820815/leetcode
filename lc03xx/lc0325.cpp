//--- Q: 0325. Maximum Size Subarray Sum Equals k

//--- method 1: prefix sum
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (map.find(sum-k) != map.end()) {
                res = max(res, i-map[sum-k]);
            }
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            }
        }
        return res;
    }
};

//--- follow up: find the array of longest subarray of sum that equals k
class Solution {
public:
    vector<int> maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0, res = 0, start;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (map.find(sum-k) != map.end()) {
                if (i-map[sum-k] > res) {
                    res = i-map[sum-k];
                    start = map[sum-k]+1;
                }
                res = max(res, i-map[sum-k]);
            }
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            }
        }
          return !res ? {} : vector<int>(nums.begin()+start, nums.begin()+start+res);
    }
};