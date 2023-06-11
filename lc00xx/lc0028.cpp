//--- Q: 0028. Implement strStr()
//--- last written: 2023/06/05

//--- method 1: one pass
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size()) {
            return 0;
        }
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n-m; ++i) {
            int j;
            for (j = 0; j < m; ++j) {
                if (needle[j] != haystack[j+i]) {
                    break;
                }
            }
            if (j == m) {
                return i;
            }
        }
        return -1;
    }
};
