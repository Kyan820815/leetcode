//--- Q: 242. Valid Anagram

//--- method 1: one pass
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> str(26, 0);
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); ++i)
            ++str[s[i]-'a'];
        for (int i = 0; i < t.size(); ++i)
            if (--str[t[i]-'a'] < 0)
                return false;
        return true;
    }
};  