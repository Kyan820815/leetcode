//--- Q: 0917. Reverse Only Letters

//--- method 1: string operation
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !isalpha(s[left])) {
                ++left;
            }
            while (left < right && !isalpha(s[right])) {
                --right;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};