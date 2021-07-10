//--- Q: 0246. Strobogrammatic Number

//--- method 1: O(1) space two pointer
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int left = 0, right = num.size()-1;
        while (left <= right) {
            if (num[left] == num[right]) {
                if (!(num[left] == '1' || num[left] == '8' || num[left] == '0')) {
                    return false;
                }                
            } else if (!(num[left] == '6' && num[right] == '9' 
                         || num[left] == '9' && num[right] == '6')) {
                return false;
            }
            ++left, --right;
        }
        return true;
    }
};