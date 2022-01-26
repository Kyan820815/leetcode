//--- Q: 1108. Defanging an IP Address

//--- method 1: inplace replacement
class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (auto &ch: address) {
            res += isdigit(ch) ? string() + ch : string() + '[' + ch + ']';
        }
        return res;
    }
};