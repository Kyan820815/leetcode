//--- Q: 1163. Last Substring in Lexicographical Order

//--- method 1: two pointer
class Solution {
public:
    string lastSubstring(string s) {
        int l = 0, r = 1, k = 0;
        while (r+k < s.size()) {
            if (s[l+k] == s[r+k]) {
                k++;
                continue;
            } else if (s[l+k] < s[r+k]) {
                l = max(l+k+1, r);
                r = l+1;
            } else {
                r += k+1;
            }
            k = 0;
        }
        return s.substr(l);
    }
};