//--- Q: 709. To Lower Case

//--- method 1: linear time pass
class Solution {
public:
    string toLowerCase(string str) {
        for (auto &ch: str) {
            if (isupper(ch)) {
                ch ^= 32;
            }
        }
        return str;
    }
};