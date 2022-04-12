//--- Q: 0338. Counting Bits

//--- method 1: bit manipulation, lsb
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = res[(i>>1)] + (i&1);
        }
        return res;
    }
};

//--- method 2: bit manipulation, last set bit
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};