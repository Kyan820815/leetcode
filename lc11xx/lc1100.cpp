//--- Q: 1100. Find K-Length Substrings With No Repeated Characters

//--- method 1: sliding window, clean code
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int left = 0, right = 0, n = s.size(), res = 0;
        vector<int> cnt(26, 0);
        while (right < n) {
            ++cnt[s[right]-'a'];
            while (cnt[s[right]-'a'] > 1) {
                --cnt[s[left++]-'a'];
            }
            res += right-left+1 >= k;
            ++right;
        }
        return res;
    }
};

//--- method 2: follow up at least length k
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int left = 0, right = 0, n = s.size(), res = 0;
        vector<int> cnt(26, 0);
        while (right < n) {
            ++cnt[s[right]-'a'];
            while (cnt[s[right]-'a'] > 1) {
                --cnt[s[left++]-'a'];
            }
            if (right-left+1 >= k) {
                res += right-left+1-k+1;
            }
            ++right;
        }
        return res;
    }
};