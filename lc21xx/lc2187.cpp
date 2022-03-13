//--- Q: 2187. Minimum Time to Complete Trips

//--- method 1: binary search
class Solution {
public:
    using ll = long long;
    long long minimumTime(vector<int>& time, int totalTrips) {
        int minv = INT_MAX;
        for (auto &v: time) {
            minv = min(minv, v);
        }
        ll left = 1, right = (ll)totalTrips*minv;
        while (left < right) {
            ll mid = left + (right-left)/2;
            ll res = 0;
            for (auto &v: time) {
                res += mid/v;
            }
            if (res < totalTrips) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};