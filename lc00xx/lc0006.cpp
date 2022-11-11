//--- Q: 0006. ZigZag Conversion
//--- last written: 2022/11/01

//--- method 1: find pattern
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res = "";
        int jump = 2*numRows-2;
        for (int i = 0; i < numRows; ++i) {
            int now = i;
            while (now < s.size()) {
                res += s[now];
                if (i > 0 && i < numRows-1 && now+(numRows-i-1)*2 < s.size()) {
                    res += s[now+(numRows-i-1)*2];
                }
                now += jump;
            }
        }
        return res;
    }
};
