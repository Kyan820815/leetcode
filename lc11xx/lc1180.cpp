//--- Q: 1180. Count Substrings with Only One Distinct Letter

//--- method 1: prefix sliding window
class Solution {
public:
    int countLetters(string s) {
        int left = 0, right = 0, res = 0, distinct = 1, prefix = 0;
        vector<int> cnt(26, 0);
        while (right < s.size()) {
            distinct -= ++cnt[s[right]-'a'] == 1;
            if (distinct < 0) {
                while (left < right && --cnt[s[left++]-'a']);
                distinct = 0, prefix = 0;
            }
            while (left < right && cnt[s[left]-'a'] > 1) {
                ++prefix, --cnt[s[left++]-'a'];
            }
            res += prefix+1;
            ++right;
        }
        return res;
    }
};

//--- method 2: linear search
class Solution {
public:
    int countLetters(string s) {
        int n = s.size(), last = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i && s[i] != s[i-1]) {
                last = i;
            }
            res += i-last+1;
        }
        return res;
    }
};