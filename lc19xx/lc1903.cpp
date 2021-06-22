//--- Q: 1903. Largest Odd Number in String

//--- method 1: find last odd number
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size()-1; i >= 0; --i) {
            if ((num[i]-'0')&1) {
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};