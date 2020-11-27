//--- Q: 345. Reverse Vowels of a String

//--- method 1: two pointer
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !vow(s[left])) {
                ++left;
            }
            while (left < right && !vow(s[right])) {
                --right;
            }
            swap(s[left], s[right]);
            ++left, --right;
        }
        return s;
    }
    bool vow(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};