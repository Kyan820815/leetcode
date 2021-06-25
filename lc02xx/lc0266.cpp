//--- Q: 266. Palindrome Permutation

//--- method 1: count odd number
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> cnt(128, 0);
        int res = 0;
        for (auto &ch: s) {
            if ((++cnt[ch])&1) {
                ++res;
            } else {
                --res;
            }
        }
        return res <= 1;
    }
};

//--- method 2: set
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> odds;
        for (auto &ch: s) {
            if (odds.find(ch) == odds.end()) {
                odds.insert(ch);
            } else {
                odds.erase(ch);
            }
        }
        return odds.size() <= 1;
    }
};