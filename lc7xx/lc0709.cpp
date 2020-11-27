//--- Q: 709. To Lower Case

//--- method 1: linear time pass
class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); ++i)
            str[i] = (isupper(str[i])) ? str[i]^32 : str[i];
        return str;
    }
};