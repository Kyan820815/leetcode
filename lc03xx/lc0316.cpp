//--- Q: 0316. Remove Duplicate Letters

//--- method 1: stack iteration
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        unordered_set<char> set;
        string sk = "";
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i]-'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            --cnt[s[i]-'a'];
            if (set.find(s[i]) != set.end()) {
                continue;
            }
            while (sk.size() && sk.back() > s[i] && cnt[sk.back()-'a'] > 0) {
                set.erase(sk.back());
                sk.pop_back();
            }
            set.insert(s[i]);
            sk.push_back(s[i]);
        }
        return sk;
    }
};