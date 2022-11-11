//--- Q: 0012. Integer to Roman
//--- last written: 2022/11/011

//--- method 1: elegant solution, better
class Solution {
public:
    string intToRoman(int num) {
        vector<vector<string>> map = {{"", "I", "II", "III", "VI", "V", "IV", "IIV", "IIIV", "XI"},
                                      {"", "X", "XX", "XXX", "LX", "L", "XL", "XXL", "XXXL", "CX"},
                                      {"", "C", "CC", "CCC", "DC", "D", "CD", "CCD", "CCCD", "MC"},
                                      {"", "M", "MM", "MMM"}};
        string res = "";
        int lv = 0;
        while (num) {
            int idx = num%10;
            num /= 10;
            res += map[lv++][idx];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//--- method 2: digit by digit processing
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> map = {{1,'I'},{5,'V'},{10,'X'},{50,'L'},
                                        {100,'C'},{500,'D'},{1000,'M'}};
        string res = "";
        int level = 1;
        while (num) {
            int rem = num%10;
            if (rem == 4 || rem == 9) {
                res += map[(rem+1)*level]; 
                res += map[level];
            } else if (rem == 5) {
                res += map[rem*level];
            } else {
                auto v = rem%5;
                while (v--) {
                    res += map[level];
                }
                if (rem/5) {
                    res += map[5*level];
                }
            }
            num /= 10;
            level *= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
