//--- Q: 374. Guess Number Higher or Lower

//--- method 1: binary search
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long left = 1, right = n;
        while (left < right)
        {
            int mid = (left+right) / 2;
            int t = guess(mid);
            if (t == -1)
                right = mid;
            else if (t == 1)
                left = mid+1;
            else return mid;
        }
        return left;
    }
};