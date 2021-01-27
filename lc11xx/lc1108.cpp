//--- Q: 1108. Defanging an IP Address

//--- method 1: inplace replacement
class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (int i = address.size()-2; i >= 0; --i) {
            if (address[i] == '.') {
                address = address.substr(0, i) + "[.]" + address.substr(i+1);
            }
        }
        return address;
    }
};

//--- method 2: extra place replacement
class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (auto s: address) {
            res += (s == '.') ? string() + '[' + s + ']' : string() + s;
        }
        return res;
    }
};