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
        int n = mountainArr.length(), left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2, mv, mv_next;
            mv = mountainArr.get(mid);
            mv_next = mountainArr.get(mid+1);
            if (mv > mv_next) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        int peak = left;
        left = 0, right = peak;
        while (left < right) {
            int mid = left + (right-left)/2, mv;
            mv = mountainArr.get(mid);
            if (mv < target) {
                left = mid+1;
            } else if (mv > target) {
                right = mid;
            } else {
                return mid;
            }
        }
        if (mountainArr.get(left) == target) {
            return left;
        }
        left = peak+1, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2, mv;
            mv = mountainArr.get(mid);
            if (mv < target) {
                right = mid;
            } else if (mv > target) {
                left = mid+1;
            } else {
                return mid;
            }
        }
        if (mountainArr.get(left) == target) {
            return left;
        } else {
            return -1;
        }
    }
};


