//--- Q: 0151. Reverse Words in a String

//--- method 1: in place reverse
class Solution {
public:
    string reverseWords(string s) {
        int cur = 0, idx = 0;
        while (idx < s.size()) {
            if (s[idx] == ' ') {
                ++idx;
                continue;
            }
            int pre = cur;
            while (idx < s.size() && s[idx] != ' ') {
                s[cur++] = s[idx++];
            }
            reverse(s.begin()+pre, s.begin()+cur);
            s[cur++] = ' ';
        }
        s = s.substr(0, cur-1);
        reverse(s.begin(), s.end());
        return s;
    }
};