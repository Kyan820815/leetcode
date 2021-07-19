//--- Q: 0383. Ransom Note

//--- method 1: array operation
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);
        for (auto &ch: magazine) {
            ++cnt[ch-'a'];
        }
        for (auto &ch: ransomNote) {
            if (--cnt[ch-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};