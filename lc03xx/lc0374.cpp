//--- Q: 0374. Guess Number Higher or Lower

//--- method 1: binary search
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left, right;
        for (left = 1, right = n; left < right;) {
            int mid = left + (right-left)/2;
            if (guess(mid) == 1) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};