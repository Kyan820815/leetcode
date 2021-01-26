//--- Q: 1231. Divide Chocolate

//--- method 1: binary search
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int left = 1, right = 0;
        for (int i = 0; i < sweetness.size(); ++i) {
            right += sweetness[i];
        }
        while (left < right) {
            int mid = left + (right - left)/2;
            if (canSplit(mid, sweetness, K)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    bool canSplit(int mid, vector<int> &sweetness, int K) {
        int sum = 0;
        for (int i = 0; i < sweetness.size(); ++i) {
            sum += sweetness[i];
            if (sum > mid) {
                sum = 0;
                if (--K < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
