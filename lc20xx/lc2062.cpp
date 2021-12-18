//--- Q: 2062. Count Vowel Substrings of a String

//--- method 1: prefix sliding window
class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int left = 0, right = 0, res = 0, times = 0, prefix = 0;
        vector<int> cnt(26, 0);
        unordered_set<char> set = {'a','e','i','o','u'};
        while (right < n) {
            if (set.find(word[right]) == set.end()) {
                left = right+1;
                cnt.clear();
                cnt.resize(26, 0);
                prefix = times = 0;
            } else {
                times += ++cnt[word[right]-'a'] == 1;
            }
            while (left < right && cnt[word[left]-'a'] > 1) {
                --cnt[word[left++]-'a'];
                ++prefix;
            }
            if (times == 5) {
                res += 1+prefix;
            }
            ++right;
        }
        return res;
    }
};
