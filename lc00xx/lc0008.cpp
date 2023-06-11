//--- Q: 0008. String to Integer (atoi)
//--- last written: 2023/05/28

//--- method 1: find first sign and digit to calculate
class Solution {
public:
    int myAtoi(string s) {
        int num = 0, sign = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == '+' || s[i] == '-') {
                sign = s[i] == '-' ? -1 : 1;
                ++i;
            }
            while (i < s.size() && isdigit(s[i])) {
                if (num > INT_MAX/10 || num == INT_MAX/10 && s[i] > '7') {
                    return INT_MAX;
                }
                if (num < INT_MIN/10 || num == INT_MIN/10 && s[i] > '8') {
                    return INT_MIN;
                }
                num = num*10 + sign*(s[i++]-'0');
            }
            break;
        }
        return num;
    }
};
