//--- Q: 1566. Detect Pattern of Length M Repeated K or More Times

//--- method 1: check i+m
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size(), cnt = 0;
        for (int i = 0; i+m < n; ++i) {
            if (arr[i] != arr[i+m]) {
                cnt = 0;
            } else if (++cnt == (k-1)*m) {
                return true;
            }
        }
        return false;
    }
};