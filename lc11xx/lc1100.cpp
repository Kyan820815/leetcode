//--- Q: 1100. Find K-Length Substrings With No Repeated Characters

//--- method 1: sliding window, clean code
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        vector<int> cnt(26, 0);
        int res = 0, left = 0, right = 0;
        while (right < S.size()) {
            ++cnt[S[right]-'a'];
            while (cnt[S[right]-'a'] > 1) {
                --cnt[S[left++]-'a'];
            }
            if (right-left+1 >= K) {
                ++res;
            }
            ++right;
        }
        return res;
    }
};

//--- method 2: sliding window
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int left = 0, right = 0, res = 0;
        vector<int> valid(26, 0);
        while (right < S.size()) {
            if (valid[S[right]-'a']) {
                 while (left < right && valid[S[right]-'a'])
                    --valid[S[left++]-'a'];
            }
            ++valid[S[right]-'a'];
            if (right-left+1 > K)
                --valid[S[left++]-'a'];
            if (right-left+1 == K)
                ++res;
            ++right;
        }
        return res;
    }
};