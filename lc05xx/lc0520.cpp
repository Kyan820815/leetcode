//--- Q: 0520. Detect Capital

//--- method 1: compare with first and second character
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        for (int i = 1; i < n; ++i) {
            if (islower(word[0]) && isupper(word[i]) || isupper(word[1]) != isupper(word[i])) {
                return false;
            }
        }
        return true;
    }
};

//--- method 2: count uppercase
class Solution {
public:
    bool detectCapitalUse(string word) {
        int up = 0;
        for (auto &ch: word) {
            if (isupper(ch)) {
                ++up;
            }
        }
        return up == word.size() || up == 1 && isupper(word[0]) || !up;
    }
};