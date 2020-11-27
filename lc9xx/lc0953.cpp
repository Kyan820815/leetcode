//--- Q: 953. Verifying an Alien Dictionary

//--- method 1: linear search
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < order.size(); ++i) {
            cnt[order[i]-'a'] = i;
        }
        for (int i = 0; i < words.size()-1; ++i) {
            if (!comp(words[i], words[i+1], cnt)) {
                return false;
            }
        }
        return true;
    }
    bool comp(string &a, string &b, vector<int> &cnt) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; ++i) {
            if (cnt[a[i]-'a'] < cnt[b[i]-'a']) {
                return true;
            } else if (cnt[a[i]-'a'] > cnt[b[i]-'a']) {
                return false;
            }
        }
        return a.size() <= b.size();
    }
};