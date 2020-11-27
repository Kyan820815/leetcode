//--- Q: 438. Find All Anagrams in a String

//--- method 1: sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cnt(26, 0), res;
        int left = 0;
        for (int i = 0; i < p.size(); ++i)
            ++cnt[p[i]-'a'];
        for (int i = 0; i < s.size(); ++i) {
            if (--cnt[s[i]-'a'] < 0) {
                while (++cnt[s[left++]-'a'] != 0);
                if (i-left+1 == p.size())
                    res.push_back(left);
            } else if (!cnt[s[i]-'a']){
                if (i-left+1 == p.size()) {
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};