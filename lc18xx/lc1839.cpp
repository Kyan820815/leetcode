//--- Q: 1839. Longest Substring Of All Vowels in Order

//--- method 1: two pointer
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int left = 0, right = 0, res = 0;
        while (right < word.size()) {
            if (right) {
                auto diff = word[right]-word[right-1];
                if (diff != 0 && diff != 4 && diff != 6) {
                    left = right;
                }
            }
            if (word[left] == 'a' && word[right] == 'u') {
                res = max(res, right-left+1);
            }
            ++right;
        }
        return res;
    }
};
