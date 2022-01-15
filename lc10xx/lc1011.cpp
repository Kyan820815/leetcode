//--- Q: 1011. Capacity To Ship Packages Within D Days

//--- method 1: binary search
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (auto &weight: weights) {
            left = max(left, weight);
            right += weight;
        }
        while (left < right) {
            int mid = left+(right-left)/2;
            if (valid(mid, weights) > days) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int valid(int val, vector<int> &weights) {
        int cnt = 1, sum = 0;
        for (auto &weight: weights) {
            sum += weight;
            if (sum > val) {
                sum = weight;
                ++cnt;
            }
        }
        return cnt;
    }
};