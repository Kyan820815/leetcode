//--- Q: 1837. Sum of Digits in Base K

//--- method 1: mod and divide
class Solution {
public:
    int sumBase(int n, int k) {
        int res = 0;
        while (n) {
            res += n%k;
            n /= k;
        }
        return res;
    }
};