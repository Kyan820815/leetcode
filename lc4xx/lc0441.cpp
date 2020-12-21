//--- Q: 441. Arranging Coins

//--- method 1: binary search
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right-left)/2;
            if ((double)(mid+1)/2 > (double)n/mid) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return (double)(left+1)/2 <= (double)n/left ? left : left-1;
    }
};