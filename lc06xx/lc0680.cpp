//--- Q: 680. Valid Palindrome II

//--- method 1: check left and right
class Solution {
public:
    int used = 1;
    bool validPalindrome(string s) {
        return find(s, 0, s.size()-1);        
    }
    bool find(string &s, int left, int right) {
        while (left < right) {
            if (s[left] == s[right]) {
                ++left, --right;
            } else if (used) {
                used = 0;
                return find(s, left+1, right) || find(s, left, right-1);
            } else {
                return false;
            }
        }
        return true;
    }
};