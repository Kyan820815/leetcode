//--- Q: 1332. Remove Palindromic Subsequences

//--- method 1: two pointers
class Solution {
public:
    int removePalindromeSub(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return 2;
            }
        }
        return 1;
    }
};
