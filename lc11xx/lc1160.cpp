//--- Q: 1160. Find Words That Can Be Formed by Characters

//--- method 1: track count
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26, 0);
        int res = 0;
        for (int i = 0; i < chars.size(); ++i) {
            ++cnt[chars[i] - 'a'];
        }
        for (int i = 0; i < words.size(); ++i) {
            vector<int> tmp = cnt;
            bool valid = true;
            for (int j = 0; j < words[i].size(); ++j) {
                if (--tmp[words[i][j]-'a'] < 0) {
                    valid = false;
                    break;
                }
            }
            res += valid ? words[i].size() : 0;
        }
        return res;
    }
};