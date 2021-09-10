//--- Q: 0763. Partition Labels

//--- method 1: two pass O(n)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> cnt(26, -1), res;
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i]-'a'] = i;
        }
        int last = cnt[s[0]-'a'], pre = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (i > last) {
                res.push_back(i-pre);
                pre = i;
            }
            last = max(last, cnt[s[i]-'a']);
        }
        res.push_back(s.size()-pre);
        return res;
    }
};