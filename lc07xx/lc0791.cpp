//--- Q: 0791. Custom Sort String

//--- method 1: count priority
class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> cnt(26, 26);
        for (int i = 0; i < order.size(); ++i) {
            cnt[order[i]-'a'] = i;
        }
        sort(str.begin(), str.end(), [&cnt](char a, char b) {
            return cnt[a-'a'] < cnt[b-'a'];
        });
        return str;
    }
};