//--- Q: 0009. Palindrome Number
//--- last written: 2023/03/11

//--- method 1: turn to string then compare
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        auto str = to_string(x);
        int left = 0, right = str.size()-1;
        while (left < right) {
            if (str[left++] != str[right--]) {
                return false;
            }
        }
        return true;
    }
};

//--- method 2: number operation
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long int left = 10, right = 10;
        while (x/left) {
            left *= 10;
        }
        while (left > right) {
            if (x%left/(left/10) != x%right/(right/10)) {
                return false;
            }
            left /= 10, right *= 10;
        }
        return true;
    }
};
