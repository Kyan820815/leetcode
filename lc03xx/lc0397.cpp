//--- Q: 0397. Integer Replacement

//--- method 2: iterative solution
# define ll long long
class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        for (ll x = n; x > 1; x /= 2) {
            if (x&1) {
                if (x%4 == 3 && x != 3) {
                    ++x;
                } else {
                    --x;
                }
                ++res;
            }
            ++res;
        }
        return res;
    }
};