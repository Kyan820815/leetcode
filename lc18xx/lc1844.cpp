//--- Q: 1844. Replace All Digits with Characters

//--- method 1: string operation
class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.size(); i+=2) {
            s[i+1] = s[i]+(s[i+1]-'0');
        }
        return s;
    }
};