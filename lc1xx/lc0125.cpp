//--- Q: 125. Valid Palindrome

//--- method 1: two pointer
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !isalpha(s[left]) && !isdigit(s[left])) {
                ++left;
            }
            while (left < right && !isalpha(s[right]) && !isdigit(s[right])) {
                --right;
            }
            if ((s[left]^32) != s[right] && s[left] != s[right]) {
                return false;
            }
            ++left, --right;
        }
        return true;
    }
};