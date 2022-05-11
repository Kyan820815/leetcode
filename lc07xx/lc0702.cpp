//--- Q: 0702. Search in a Sorted Array of Unknown Size

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

//--- method 1: find upper and lower bound the do bs
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left, right = 1;
        while (reader.get(right) < target) {
            right <<= 1;
        }
        left = right >> 1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (reader.get(mid) < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return reader.get(left) != target ? -1 : left;
    }
};