//--- Q: 1616. Split Two Strings to Make Palindrome

//--- method 1: linear find
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return valid(a, b) || valid(b, a);
    }
    bool valid(string &a, string &b) {
        int i = 0, j = b.size()-1;
        while (i < j) {
            if (a[i] != b[j]) {
                return same_valid(a, i, j) || same_valid(b, i, j);
            }
            ++i, --j;
        }
        return true;
    }
    bool same_valid(string &str, int i, int j) {
        while (i < j) {
            if (str[i++] != str[j--]) {
                return false;
            }
        }
        return true;
    }
};