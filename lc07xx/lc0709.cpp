//--- Q: 0709. To Lower Case

//--- method 1: built-in function
class Solution {
public:
    string toLowerCase(string s) {
        for (auto &ch: s) {
            if (isupper(ch)) {
                ch = tolower(ch);
            }
        }
        return s;
    }
};

//--- method 2: xor
class Solution {
public:
    string toLowerCase(string s) {
        for (auto &ch: s) {
            if (isupper(ch)) {
                ch ^= 32;
            }
        }
        return s;
    }
};