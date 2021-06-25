//--- Q: 1704. Determine if String Halves Are Alike

//--- method 1: linear find
class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0, j = s.size()/2; i < s.size()/2; ++i, ++j) {
            if (set.find(s[i]) != set.end() || set.find(s[i]^32) != set.end()) {
                ++cnt;
            }
            if (set.find(s[j]) != set.end() || set.find(s[j]^32) != set.end()) {
                --cnt;
            }
        }
        return !cnt;
    }
};