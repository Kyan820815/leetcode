//--- Q: 1646. Get Maximum in Generated Array

//--- method 1: array simulation
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) {
            return n;
        }
        vector<int> arr = {0,1};
        int res = 1;
        for (int i = 2; i <= n; ++i) {
            arr.push_back(arr[i>>1]);
            arr.back() += i&1 ? arr[(i>>1)+1] : 0;
            res = max(res, arr.back());
        }
        return res;
    }
};