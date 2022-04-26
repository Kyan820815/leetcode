//--- Q: 1529. Minimum Suffix Flips

//--- method 1: odd & even flip times
class Solution {
public:
    int minFlips(string target) {
        int res = 0;
        for (int i = 0; i < target.size(); ++i) {
            if (target[i] != (res&1)+'0') {
                ++res;
            }
        }
        return res;
    }
};