//--- Q: 0476. Number Complement

//--- method 1: bit operation
class Solution {
public:
    int findComplement(int num) {
        int mask = 0, tmp = num;
        while (tmp) {
            mask = (mask << 1) | 1;
            tmp >>= 1;
        }
        return (~num)&mask;
    }
};

