//--- Q: 0402. Remove K Digits

//--- method 1: increasin stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (int i = 0; i < num.size(); ++i) {
            while (res.size() && res.back() > num[i] && k) {
                --k;
                res.pop_back();
            }
            res += num[i];
        }
        while (res.size() && --k >= 0) {
            res.pop_back();
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }
        return "0";
    }
};

//--- follow up:
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (int i = 0; i < num.size(); ++i) {
            while (res.size() && res.back() < num[i] && k) {
                --k;
                res.pop_back();
            }
            res += num[i];
        }
        while (res.size() && --k >= 0) {
            res.pop_back();
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }
        return "0";
    }
};