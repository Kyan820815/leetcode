//--- Q: 2068. Check Whether Two Strings are Almost Equivalent

//--- method 1: bucket checking
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> cnt(26, 0);
        int n = word1.size();
        for (int i = 0; i < n; ++i) {
            ++cnt[word1[i]-'a'];
            --cnt[word2[i]-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (abs(cnt[i]) > 3) {
                return false;
            }
        }
        return true;
    }
};