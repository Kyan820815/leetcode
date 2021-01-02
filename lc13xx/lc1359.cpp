//--- Q: 1359. Count All Valid Pickup and Delivery Options

//--- method 1: math
class Solution {
public:
    int countOrders(int n) {
        long long int mod = 1e9+7, res = 1;
        for (int i = 1; i <= n; ++i) {
            res = res * (2*i-1)*i % mod;
        }
        return res;
    }
};