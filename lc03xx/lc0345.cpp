//--- Q: 0345. Reverse Vowels of a String

//--- method 1: two pointer
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> set = {'a','e','i','o','u','A','E','I','O','U'};
        for (int i = 0, j = s.size()-1; i < j; ++i, --j) {
            for (; i<j && set.find(s[i]) == set.end(); ++i);
            for (; i<j && set.find(s[j]) == set.end(); --j);
            swap(s[i], s[j]);
        }
        return s;
    }
};