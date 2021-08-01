//--- Q: 0557. Reverse Words in a String III

//--- method 1: reverse string when facing space
class Solution {
public:
    string reverseWords(string s) {
        int i, j;
        for (i = 0; i < s.size();) {
            for (j = i; j < s.size() && s[j] != ' '; ++j);
            reverse(s.begin()+i, s.begin()+j);
            i = j+1;
        }
        return s;
    }
};