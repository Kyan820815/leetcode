//--- Q: 1002. Find Common Characters

//--- method 1: O(n) time find comman ch
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26, INT_MAX);
        vector<string> res;
        for (int i = 0; i < A.size(); ++i) {
            vector<int> tmp(26, 0);
            for (int j = 0; j < A[i].size(); ++j) {
                ++tmp[A[i][j]-'a'];
            }
            for (int j = 0; j < 26; ++j) {
                cnt[j] = min(cnt[j], tmp[j]);
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                res.push_back(string(1, i+'a'));
            }
        }
        return res;
    }
};
