//--- Q: 2185. Counting Words With a Given Prefix

//--- method 1: substring
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (auto &word: words) {
            res += word.substr(0, pref.size()) == pref;
        }
        return res;
    }
};

//--- method 2: find
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (auto &word: words) {
            res += !word.find(pref);
        }
        return res;
    }
};