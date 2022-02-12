//--- Q: 2163. Minimum Difference in Sums After Removal of Elements

//--- method 1: priority queue sliding window
class Solution {
public:
    using ll = long long;
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size(), m = n/3;
        vector<ll> per_min, per_max;
        ll left = 0, right = 0;
        priority_queue<ll, vector<ll>, greater<ll>> rightque;
        priority_queue<ll> leftque;
        for (int i = 0; i < m; ++i) {
            left += nums[i];
            leftque.push(nums[i]);
            right += nums[n-i-1];
            rightque.push(nums[n-i-1]);
        }
        per_min.push_back(left);
        per_max.push_back(right);
        int boundary = 2*m;
        for (int i = m; i < boundary; ++i) {
            if (leftque.top() > nums[i]) {
                left -= leftque.top();
                left += nums[i];
                leftque.pop();
                leftque.push(nums[i]);
            }
            per_min.push_back(left);
            if (rightque.top() < nums[n-i-1]) {
                right -= rightque.top();
                right += nums[n-i-1];
                rightque.pop();
                rightque.push(nums[n-i-1]);
            }
            per_max.push_back(right);
        }
        ll res = LONG_MAX, k = per_min.size();
        for (int i = 0; i < k; ++i) {
            res = min(res, per_min[i]-per_max[k-i-1]);
        }
        return res;
    }
};