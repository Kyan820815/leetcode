//--- Q: 0186. Reverse Words in a String II

//--- method 1: string processing
class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size(), i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            int last = i;
            while (i < n && s[i] != ' ') {
                ++i;
            }
            reverse(s.begin()+last, s.begin()+i);
        }
        reverse(s.begin(), s.end());
    }
};