//--- Q: 0273. Integer to English Words

//--- method 1: dfs recursion
class Solution {
public:
    vector<string> under20 = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", 
                              "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    vector<string> under100 = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    vector<string> level = {"", "Thousand ", "Million ", "Billion "};
    string numberToWords(int num) {
        if (!num) {
            return "Zero";
        }
        string res = "";
        int lv = 0;
        while (num) {
            int rem = num % 1000;
            if (rem) {
                res = dfs(rem) + level[lv] + res;
            }
            ++lv;
            num /= 1000;
        }
        res.pop_back();
        return res;
    }
    string dfs(int num) {
        if (num < 20) {
            return under20[num];
        } else if (num < 100) {
            return under100[num/10] + under20[num%10];
        } else {
            return under20[num/100] + "Hundred " + dfs(num%100);
        }
    }
};