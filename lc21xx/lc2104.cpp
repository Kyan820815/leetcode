//--- Q: 2104. Sum of Subarray Ranges

//--- method 1: two stack
class Solution {
public:
    using ll = long long;
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        ll res = 0;
        vector<ll> minsk = {-1}, maxsk = {-1};
        for (int i = 0; i <= n; ++i) {
            int curmin = i == n ? INT_MIN : nums[i];
            int curmax = i == n ? INT_MAX : nums[i];
            while (minsk.back() != -1 && nums[minsk.back()] > curmin) {
                int idx = minsk.back();
                minsk.pop_back();
                res -= (idx-minsk.back())*(i-idx)*nums[idx];
            }
            while (maxsk.back() != -1 && nums[maxsk.back()] < curmax) {
                int idx = maxsk.back();
                maxsk.pop_back();
                res += (idx-maxsk.back())*(i-idx)*nums[idx];
            }
            minsk.push_back(i);
            maxsk.push_back(i);
        }
        return res;
    }
};

//--- method 2: dp with stack
class Solution {
public:
    using ll = long long;
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        ll res = 0;
        vector<ll> minsk = {-1}, maxsk = {-1};
        vector<ll> mindp(n, 0), maxdp(n, 0);
        for (int i = 0; i < n; ++i) {
            while (minsk.back() != -1 && nums[minsk.back()] > nums[i]) {
                minsk.pop_back();
            }
            while (maxsk.back() != -1 && nums[maxsk.back()] < nums[i]) {
                maxsk.pop_back();
            }
            ll lastmin = minsk.back() != -1 ? mindp[minsk.back()] : 0;
            ll lastmax = maxsk.back() != -1 ? maxdp[maxsk.back()] : 0;
            mindp[i] = lastmin + (i-minsk.back())*nums[i];
            maxdp[i] = lastmax + (i-maxsk.back())*nums[i];
            minsk.push_back(i);
            maxsk.push_back(i);
            res += maxdp[i]-mindp[i];
        }
        return res;
    }
};