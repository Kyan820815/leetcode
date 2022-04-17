//--- Q: 0868. Binary Gap

//--- method 1: bit
class Solution {
public:
    int binaryGap(int n) {
        int res = 0, last = -1, idx = 0;
        while (n) {
            if (n&1) {
                if (last != -1) {
                    res = max(res, idx-last);
                }
                last = idx;
            }
            ++idx;
            n >>= 1;
        }
        return res;
    }
};