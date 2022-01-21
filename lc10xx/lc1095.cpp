//--- Q: 1095. Find in Mountain Array

//--- method 1: triple binary search
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        int pivot = left;
        left = 0, right = pivot;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (mountainArr.get(mid) < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        if (mountainArr.get(left) == target) {
            return left;
        }
        left = pivot, right = mountainArr.length()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (mountainArr.get(mid) > target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return mountainArr.get(left) == target ? left : -1;
    }
};