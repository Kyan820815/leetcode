//--- Q: 0862. Shortest Subarray with Sum at Least K

//--- method 1: sliding window
class Solution {
public:
    using ll = long long;
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), right = 0, res = INT_MAX;
        vector<ll> arr;
        ll sum = 0;
        deque<int> que;
        while (right < n) {
            sum += nums[right];
            arr.push_back(sum);
            if (arr[right] >= k) {
                res = min(res, right+1);
            }
            while (que.size() && arr[right]-arr[que.front()] >= k) {
                res = min(res, right-que.front());
                que.pop_front();
            }
            while (que.size() && arr[right]-arr[que.back()] <= 0) {
                que.pop_back();
            }
            que.push_back(right++);
        }
        return res == INT_MAX ? -1 : res;
    }
};