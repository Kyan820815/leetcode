//--- Q: 0367. Valid Perfect Square

//--- method 1: binary search
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left < right) {
            int mid = left + (right-left)/2;
            if ((double)mid < (double)num/mid) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return num%left == 0 && left == num/left;
    }
};