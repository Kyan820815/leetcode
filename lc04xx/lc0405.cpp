//--- Q: 0405. Convert a Number to Hexadecimal

//--- method 1: bit manipulation
class Solution {
public:
    string toHex(int num) {
        string hex = "0123456789abcdef";
        string res = "";
        int cnt = 0;
        if (!num) {
            return "0";
        }
        while (num && ++cnt <= 8) {
            res = hex[num & 0xf] + res;
            num >>= 4;
        }
        return res;
    }
};

//--- follow up: Convert a Number to Binary
class Solution {
public:
    string toHex(int num) {
        string res = "";
        int cnt = 0;
        if (!num) {
            return "0";
        }
        while (num && ++cnt <= 32) {
            char digit = '0' + (num&1);
            res = digit + res;
            num >>= 1;
        }
        return res;
    }
};