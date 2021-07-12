//--- Q: 0266. Palindrome Permutation

//--- method 2: set
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> set;
        for (auto &ch: s) {
            if (set.find(ch) != set.end()) {
                set.erase(ch);
            } else {
                set.insert(ch);
            }
        }
        return set.size() <= 1;
    }
};