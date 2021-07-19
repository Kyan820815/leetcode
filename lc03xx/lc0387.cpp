//--- Q: 0387. First Unique Character in a String

//--- method 1: counting sort
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        for (auto &ch: s) {
            ++cnt[ch-'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};