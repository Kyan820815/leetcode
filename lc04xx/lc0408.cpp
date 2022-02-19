//--- Q: 0408. Valid Word Abbreviation

//--- method 1: two pointers
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (isalpha(abbr[j])) {
                if (word[i] != abbr[j]) {
                    return false;
                }
                ++i, ++j;
            } else if (abbr[j] != '0') {
                int times = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    times = times*10 + (abbr[j++]-'0');
                }
                if (i + times > word.size()) {
                    return false;
                }
                i += times;
            } else {
                return false;
            }
        }
        return i == word.size() && j == abbr.size();
    }
};