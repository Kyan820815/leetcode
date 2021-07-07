//--- Q: 0171. Excel Sheet Column Number

//--- method 1: string operation
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (auto &ch: columnTitle) {
            res = res*26 + (ch-'A') + 1;
        }
        return res;
    }
};