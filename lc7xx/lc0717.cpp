//--- Q: 717. 1-bit and 2-bit Characters

//--- method 1: traverse all array
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size()-1) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                ++i;
            }
        }
        return i == bits.size()-1;
    }
};

//--- method 2: reverse array traversal
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ones = 0;
        for (int i = bits.size()-2; i >= 0 && bits[i] == 1; --i, ++ones);
        return ones % 2 == 0;
    }
};