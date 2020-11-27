//--- Q: 1071. Greatest Common Divisor of Strings

//--- method 1: iterative find gcd
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        while (str1.size() && str2.size()) {
            if (str1.size() < str2.size()) {
                swap(str1, str2);
            }
            if (str1.substr(0, str2.size()) == str2) {
                str1 = str1.substr(str2.size());
            } else {
                return "";
            }
        }
        return str2;
    }
};