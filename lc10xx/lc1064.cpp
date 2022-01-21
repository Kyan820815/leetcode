//--- Q: 1064. Fixed Point

//--- method 1: binary search
class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int left = 0, right = arr.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (arr[mid] < mid) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return arr[left] == left ? left : -1;
    }
};