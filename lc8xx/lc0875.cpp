//--- Q: 875. Koko Eating Bananas

//--- method 1: binary search
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = INT_MIN;
        for (int i = 0; i < piles.size(); ++i) {
            right = max(right, piles[i]);
        }
        while (left < right) {
            int mid = left + (right-left)/2;
            if (eatAll(mid, H, piles)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    bool eatAll(int num, int h, vector<int> &piles) {
        int cnt = 0;
        for (int i = 0; i < piles.size(); ++i) {
            cnt += (piles[i]+num-1) / num;
        }
        return cnt <= h;
    }
};