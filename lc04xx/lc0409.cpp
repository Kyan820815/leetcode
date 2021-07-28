//--- Q: 0409. Longest Palindrome

//--- method 1: set operation
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> set;
        int res = 0;
        for (auto &ch: s) {
            if (set.find(ch) != set.end()) {
                set.erase(ch);
                res += 2;
            } else {
                set.insert(ch);
            }
        }
        return res + (set.size() > 0);
    }
};

//--- method 2: find largest odd & even, then add
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(128, 0);
        int one = 0, res = 0;
        for (auto &ch: s) {
            if (++cnt[ch] == 2) {
                res += 2;
                cnt[ch] = 0;
                --one;
            } else {
                ++one;
            }
        }
        return res + (one > 0);
    }
};