//--- Q: 0845. Longest Mountain in Array

//--- method 1: two pointer, clean code
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), res = 0, left = 0, right = 0;
        while (right < n) {
            while (right+1 < n && arr[right] >= arr[right+1]) {
                ++right;
            }
            left = right;
            while (right+1 < n && arr[right] < arr[right+1]) {
                ++right;
            }
            if (right == n-1 || arr[right] == arr[right+1]) {
                ++right;
                continue;
            }
            while (right+1 < n && arr[right] > arr[right+1]) {
                ++right;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};