//--- Q: 0231. Power of Two

//--- method 1: O(1) time
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 ? !(n&(n-1)) : false;
    }
};