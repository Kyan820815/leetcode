//--- Q: 316. Remove Duplicate Letters

//--- method 1: stack iteration
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0), exist(26, 0);
        string res = "";
        for (auto &c: s) {
            ++cnt[c-'a'];
        }
        for (auto &c: s) {
            if (!exist[c-'a']) {
                exist[c-'a'] = 1;
                while (res.size() && c < res.back() && cnt[res.back()-'a']) {
                    exist[res.back()-'a'] = 0;
                    res.pop_back();
                }
                res.push_back(c);
            }
            --cnt[c-'a'];
        }
        return res;
    }
};
