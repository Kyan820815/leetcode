//--- Q: 2108. Find First Palindromic String in the Array

//--- method 1: process each string
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &word: words) {
            int left = 0, right = word.size()-1, valid = 1;
            while (left < right) {
                if (word[left++] != word[right--]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                return word;
            }
        }
        return "";
    }
};