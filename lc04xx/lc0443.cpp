//--- Q: 0443. String Compression

//--- method 1: O(1) space
class Solution {
public:
    int compress(vector<char>& chars) {
        int idx, i, cnt = 1;
        for (idx = -1, i = 1; i <= chars.size(); ++i) {
            if (i == chars.size() || chars[i] != chars[i-1]) {
                chars[++idx] = chars[i-1];
                if (cnt > 1) {
                    string cnt_str = to_string(cnt);
                    for (auto &ch: cnt_str) {
                        chars[++idx] = ch;
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