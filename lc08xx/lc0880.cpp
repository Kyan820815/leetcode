//--- Q: 0880. Decoded String at Index

//--- method 1: work backward, O(1) space
class Solution {
public:
    using ll = long long;
    string decodeAtIndex(string s, int k) {
        ll len = 0;
        int i;
        for (i = 0; len < k; ++i) {
            if (isalpha(s[i])) {
                ++len;
            } else {
                len *= (s[i]-'0');
            }
        }
        --i;
        while (i >= 0) {
            if (isdigit(s[i])) {
                len /= (s[i]-'0');
                if (k % len == 0) {
                    k = len;
                } else {
                    k %= len;
                }
            } else {
                if (k == len) {
                    break;
                }
                --len;
            }
            i--;
        }
        return string()+s[i];
    }
};