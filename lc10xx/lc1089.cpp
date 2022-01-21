//--- Q: 1089. Duplicate Zeros

//--- method 1: O(n) time, O(1) space
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), zeros = 0;
        for (auto &val: arr) {
            zeros += !val;
        }
        int i = n+zeros, j = n-1;
        while (j >= 0) {
            if (--i < n) {
                arr[i] = arr[j];
            }
            if (!arr[j] && --i < n) {
                arr[i] = arr[j];
            }
            --j;
        }
    }
};