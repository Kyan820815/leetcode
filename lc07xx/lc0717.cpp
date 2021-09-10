//--- Q: 0717. 1-bit and 2-bit Characters

//--- method 1: traverse all array
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i;
        for (i = 0; i < bits.size()-1; ++i) {
            i += bits[i] == 1;
        }
        return i == bits.size()-1;
    }
};

//--- method 2: find pattern
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ones = 0;
        for (int i = bits.size()-1; i >= 0 && bits[i] == 1; --i, ++ones);
        return !(ones&1);
    }
};