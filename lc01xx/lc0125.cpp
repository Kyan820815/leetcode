//--- Q: 0125. Valid Palindrome
//--- last written: 2023/07/14

//--- method 1: two pointer
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            while (i < j && !(isdigit(s[i]) || isalpha(s[i]))) {
                ++i;
            }
            while (i < j && !(isdigit(s[j]) || isalpha(s[j]))) {
                --j;
            }
            if ((s[i]^32) == s[j] || s[i] == s[j]) {
                ++i, --j;
            } else {
                return false;
            }
        }
        return true;
    }
};
