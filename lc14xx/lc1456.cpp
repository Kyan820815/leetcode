//--- Q: 1456. Maximum Number of Vowels in a Substring of Given Length

//--- method 1: sliding window
class Solution {
public:
    int maxVowels(string s, int k) {
        array<int,26> set = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
        int cnt = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            cnt += set[s[i]-'a'];
            if (i-k >= 0) {
                cnt -= set[s[i-k]-'a'];
            }
            res = max(res, cnt);
        }
        return res;
    }
};