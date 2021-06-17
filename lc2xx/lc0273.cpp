//--- Q: 273. Integer to English Words

//--- method 1: dfs recursion
class Solution {
public:
    vector<string> undertwenty = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ",
                                 "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    vector<string> underhundred = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    vector<string> underthousand = {"", "Thousand ", "Million ", "Billion "};
    
    string numberToWords(int num) {
        if (!num) {
            return "Zero";
        }
        string res = "";
        int i = 0;
        while (num) {
            if (num%1000) {
                res = dfs(num%1000) + underthousand[i] + res;
            }
            num /= 1000;
            ++i;
        }
        res.pop_back();
        return res;
    }
    string dfs(int num) {
        string wd = "";
        if (num < 20) {
            wd = undertwenty[num];
        } else if (num < 100) {
            wd = underhundred[num/10] + undertwenty[num%10];
        } else {
            wd = undertwenty[num/100] + "Hundred " + dfs(num%100);
        }
        return wd;
    }
};