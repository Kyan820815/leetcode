//--- Q: 278. First Bad Version

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

//--- method 1: binary search
class Solution {
public:
    int firstBadVersion(int n) {
        long long int left = 0, right = n-1;
        while (left < right) {
            long long int mid = (left+right) / 2;
            if (isBadVersion(mid+1))
                right = mid;
            else
                left = mid+1;
        }
        return left+1;
    }
};