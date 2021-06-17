//--- Q: 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

//--- method 1: prefix sum
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> map;
        int sum = 0, lv = INT_MAX, res = INT_MAX;
        map[0] = -1;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            map[sum] = i;
        }
        sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (map.find(sum-target) != map.end()) {
                lv = min(lv, i-map[sum-target]);
            }
            if (lv != INT_MAX && map.find(sum+target) != map.end()) {
                res = min(res, map[sum+target]-i+lv);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

//--- method 2: sliding window
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), res = INT_MAX, sum = 0, left = 0, right = 0, best_left = INT_MAX;
        vector<int> dp(n, INT_MAX);
        while (right < arr.size()) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left++];
            }
            if (sum == target) {
                if (left > 0 && dp[left-1] != INT_MAX) {
                    res = min(res, dp[left-1]+right-left+1);
                }
                best_left = min(best_left, right-left+1);
            }
            dp[right++] = best_left;
        }
        return res == INT_MAX ? -1 : res;
    }
};