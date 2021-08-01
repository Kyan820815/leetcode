//--- Q: 0537. Complex Number Multiplication

//--- method 1: math computation
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int l1 = 0, r1 = 0, l2 = 0, r2 = 0, l = 0, r = 0;
        str2int(num1, l1, r1);
        str2int(num2, l2, r2);
        l = l1*l2-r1*r2;
        r = l1*r2+l2*r1;
        return to_string(l) + "+" + to_string(r) + "i";
    }
    void str2int(string &str, int &left, int &right) {
        int i = 0, sign = 1;
        if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        for (; str[i] != '+'; ++i) {
            left = left*10 + (str[i]-'0');
        }
        left *= sign;
        sign = 1;
        if (str[++i] == '-') {
            sign = -1;
            ++i;
        }
        for (; str[i] != 'i'; ++i) {
            right = right*10 + (str[i]-'0');
        }
        right *= sign;
    }
};