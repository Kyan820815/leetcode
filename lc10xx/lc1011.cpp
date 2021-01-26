//--- Q: 1011. Capacity To Ship Packages Within D Days

//--- method 1: binary search
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 0;
        for (int i = 0; i < weights.size(); ++i) {
            left = max(left, weights[i]);
            right += weights[i];
        }
        while (left < right) {
            int mid = left + (right-left)/2;
            if (canLoad(weights, D, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    bool canLoad(vector<int> &weights, int D, int T) {
        int sum = weights[0], cnt = 1;
        for (int i = 1; i < weights.size(); ++i) {
            sum += weights[i];
            if (sum > T) {
                sum = weights[i];
                if (++cnt > D) {
                    return false;
                }
            }
        }
        return true;
    }
};
