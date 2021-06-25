//--- Q: 557. Reverse Words in a String III

//--- method 1: reverse string when facing space
class Solution {
public:
    string reverseWords(string s) {
        int last = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                int len = i-last;
                for (int j = 0; j < len/2; ++j) {
                    swap(s[j+last], s[len+last-1-j]);
                }
                last = i+1;
            }
        }
        return s;
    }
};