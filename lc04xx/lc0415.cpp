//--- Q: 415. Add Strings

//--- method 1: linear processing
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0, i = num1.size()-1, j = num2.size()-1;
        while (i >= 0 || j >= 0 || carry) {
            int iv = (i >= 0) ? num1[i--]-'0' : 0;
            int jv = (j >= 0) ? num2[j--]-'0' : 0;
            res = to_string((iv + jv + carry) % 10) + res;
            carry = (iv + jv + carry) / 10;
        }
        return res;
    }
};