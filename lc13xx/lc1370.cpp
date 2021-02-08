//--- Q: 1370. Increasing Decreasing String

//--- method 1: bucket sort
class Solution {
public:
    string sortString(string s) {
        string res = "";
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i]-'a'];
        }
        int d = 1;
        while (res.size() < s.size()) {
            int start = d == 1 ? 0 : 25;
            for (int i = start; i <= 25 && i >= 0; i+=d) {
                if (cnt[i]) {
                    --cnt[i];
                    res.push_back(i+'a');
                }
            }
            d *= -1;
        }
        return res;
    }
};