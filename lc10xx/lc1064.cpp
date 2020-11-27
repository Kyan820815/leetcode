//--- Q: 1064. Fixed Point

//--- method 1: binary search
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int left = 0, right = A.size()-1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (A[mid] < mid) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return A[left] == left ? left : -1;
    }
};