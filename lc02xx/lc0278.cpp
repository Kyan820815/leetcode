//--- Q: 0278. First Bad Version

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

//--- method 1: binary search
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (!isBadVersion(mid)) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};