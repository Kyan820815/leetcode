//--- Q: 1754. Largest Merge Of Two Strings

//--- method 1: string compare
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res = "", str1 = word1, str2 = word2;
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            if (str1 < str2) {
                res += word2[j++];
                str2 = word2.substr(j);
            } else {
                res += word1[i++];
                str1 = word1.substr(i);
            }
        }
        res += word1.substr(i);
        res += word2.substr(j);
        return res;
    }
};