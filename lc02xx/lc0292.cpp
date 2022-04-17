//--- Q: 0292. Nim Game

//--- method 1: find pattern
class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};