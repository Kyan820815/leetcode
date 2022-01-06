//--- Q: 0953. Verifying an Alien Dictionary

//--- method 1: linear search
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> idx(26, 0);
        for (int i = 0; i < 26; ++i) {
            idx[order[i]-'a'] = i;
        }
        int n = words.size();
        for (int i = 1; i < n; ++i) {
            if (!comp(words[i-1], words[i], idx)) {
                return false;
            }
        }
        return true;
    }
    bool comp(string &a, string &b, vector<int> &idx) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (idx[a[i]-'a'] < idx[b[j]-'a']) {
                return true;
            } else if (idx[a[i]-'a'] > idx[b[j]-'a']) {
                return false;
            }
            ++i, ++j;
        }
        return i == a.size();
    }
};