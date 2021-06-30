//--- Q: 0069. Sqrt(x)

//--- method 1: binary search
class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (mid < (double)x/mid) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left > (double)x/left ? left-1 : left;
    }
};