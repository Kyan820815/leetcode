//--- Q: 2119. A Number After a Double Reversal

//--- method 1: find pattern
class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num%10 != 0 || num == 0;
    }
};