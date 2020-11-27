//--- Q: 58. Length of Last Word

//--- method 1: string operation
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (!s.size()) return 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ') continue;
            if (i > 0 && s[i-1] == ' ' && s[i]-'A' >= 0) cnt = 1;
            else ++cnt;
        }
        return cnt;
    }
};