//--- Q: 0043. Multiply Strings
//--- last written: 2023/03/14

//--- method 1: back multiplication
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size(), start;
        string res(n1+n2+1, '0');
        start = res.size()-1;
        for (int i = n1-1; i >= 0; --i) {
            int carry = 0, idx = start--;
            for (int j = n2-1; j >= 0; --j) {
                carry += (num1[i]-'0')*(num2[j]-'0') + (res[idx]-'0');
                res[idx--] = carry%10+'0';
                carry /= 10;
            }
            if (carry) {
                res[idx] = carry+'0';
            }
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }
        return "0";
    }
};
