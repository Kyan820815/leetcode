//--- Q: 443. String Compression

//--- method 1: O(1) space
class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = -1, cnt = 1;
        for (int i = 1; i <= chars.size(); ++i) {
            if (i == chars.size() || chars[i] != chars[i-1]) {
                chars[++idx] = chars[i-1];
                if (cnt > 1) {
                    string num = to_string(cnt);
                    for (int j = 0; j < num.size(); ++j) {
                        chars[++idx] = num[j];
                    }
                    cnt = 1;
                }
            } else {
                ++cnt;
            }
        }
        return idx+1;
    }
};