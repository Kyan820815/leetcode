//--- Q: 476. Number Complement

//--- method 1: bit operation
class Solution {
public:
    int findComplement(int num) {
    	int bit = 0, res = 0;
    	while (num > 0) {
    		res |= (((num&1)^1) << bit++);
    		num >>= 1;
    	}
        return res;
    }
};

//--- method 2:
class Solution {
public:
    int findComplement(int num) {
        int len = 0, mask = 0, res = ~num;
        while (num) {
            num >>= 1;
            mask = (mask << 1) | 1;
        }
        return mask&res;
    }
};