//--- Q: 2180. Count Integers With Even Digit Sum

//--- method 1: brute force
class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = 2; i <= num; ++i) {
            int v = i, s = 0;
            while (v) {
                s += v%10;
                v /= 10;
            }
            if (!(s&1)) {
                ++res;
            }
        }
        return res;
    }
};

//--- method 2: find pattern
class Solution {
public:
    int countEven(int num) {
        int res = 0, sum = 0, val = num;
        while (val) {
            sum += val%10;
            val /= 10;
        }
        return (sum&1) ? (num-1)/2 : num/2;
    }
};