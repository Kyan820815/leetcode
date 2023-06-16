//--- Q: 0058. Length of Last Word
//--- last written: 2023/06/16

//--- method 1: string operation
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, j;
        for (i = s.size()-1; i >= 0; --i) {
            if (s[i] != ' ') {
                break;
            }
        }
        for (j = i; j >= 0; --j) {
            if (s[j] == ' ') {
                break;
            }
        }
        return i-j;
    }
};
