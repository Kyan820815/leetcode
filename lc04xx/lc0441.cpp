//--- Q: 0441. Arranging Coins

//--- method 1: binary search
class Solution {
public:
    int arrangeCoins(int n) {
        int left, right;
        for (left = 1, right = n; left < right;) {
            int mid = left + (right-left)/2;
            if ((double)(1+mid)/2 < (double)n/mid) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return (double)(1+left)/2 > (double)n/left ? left-1 : left;
    }
};