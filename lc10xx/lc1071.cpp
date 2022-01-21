//--- Q: 1071. Greatest Common Divisor of Strings

//--- method 1: iterative find gcd
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        while (str1.size() && str2.size()) {
            find(str1, str2);
        }
        return str1;
    }
    void find(string &a, string &b) {
        int i;
        for (i = 0; i+b.size() <= a.size(); i += b.size()) {
            if (a.substr(i, b.size()) != b) {
                a = b = "";
                return;
            }
        }
        auto tmp = a.substr(i);
        a = b;
        b = tmp;
    }
};