//--- Q: 246. Strobogrammatic Number

//--- method 1: O(1) space
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.size()-1;
        while (i <= j) {
            if ((num[i] == num[j] && (num[i] == '0' || num[i] == '1' || num[i] == '8')) 
                || (num[i] == '6' && num[j] == '9') || (num[i] == '9' && num[j] == '6')) {
                ++i;
                --j;
                continue;
            }
            return false;
        }
        return true;
    }
};