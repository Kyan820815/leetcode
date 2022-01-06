//--- Q: 0978. Longest Turbulent Subarray

//--- method 1: O(n) time, O(1) space
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), dir = -1, len = 1, res = 1;
        for (int i = 1; i < n; ++i) {
            if ((arr[i-1] < arr[i] && (dir == -1 || dir == 1)) || (arr[i-1] > arr[i] && (dir == -1 || !dir))) {
                ++len;
                if (dir != -1) {
                    dir ^= 1;
                } else {
                    dir = arr[i-1] > arr[i];
                }
            } else {
                res = max(res, len);
                if (arr[i-1] > arr[i] || arr[i-1] < arr[i]) {
                    len = 2;
                } else {
                    len = 1;
                    dir = -1;
                }
            }
        }
        res = max(res, len);
        return res;
    }
};