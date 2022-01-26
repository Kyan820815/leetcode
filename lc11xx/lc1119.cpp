//--- Q: 1119. Remove Vowels from a String

//--- method 1: one time pass
class Solution {
public:
    string removeVowels(string s) {
        string res = "";
        vector<int> cnt(26, 0);
        cnt['a'-'a'] = cnt['e'-'a'] = cnt['i'-'a'] = cnt['o'-'a'] = cnt['u'-'a'] = 1;
        for (auto &ch: s) {
            if (!cnt[ch-'a']) {
                res += ch;
            }
        }
        return res;
    }
};