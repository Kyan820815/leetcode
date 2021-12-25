//--- Q: 0875. Koko Eating Bananas

//--- method 1: binary search
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1;
        for (auto &pile: piles) {
            right = max(right, pile);
        }
        while (left < right) {
            int mid = left + (right-left)/2;
            if (count(piles, mid) > h) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int count(vector<int> piles, int val) {
        int cnt = 0;
        for (auto &pile: piles) {
            cnt += (pile+val-1)/(val);
        }
        return cnt;
    }
};