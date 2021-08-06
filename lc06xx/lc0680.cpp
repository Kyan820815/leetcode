//--- Q: 0680. Valid Palindrome II

//--- method 1: check left and right
class Solution {
public:
    int chance = 1;
    bool validPalindrome(string s) {
        return findpali(0, s.size()-1, s);
    }
    bool findpali(int left, int right, string &s) {
        for (; left < right; ++left, --right) {
            if (s[left] != s[right]) {
                if (--chance < 0) {
                    return false;
                } else {
                    return findpali(left+1, right, s) || findpali(left, right-1, s);
                }
            }
        }
        return true;
    }
};