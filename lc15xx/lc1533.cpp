//--- Q: 1533. Find the Index of the Large Integer

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

//--- method 1: binary search
class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n = reader.length();
        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            int llen = mid-left+1, rlen = right-mid;
            int limit = llen > rlen ? mid-1 : mid;
            int val = reader.compareSub(left, limit, mid+1, right);
            if (val == -1) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
