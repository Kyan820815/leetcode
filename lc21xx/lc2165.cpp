//--- Q: 2165. Smallest Value of the Rearranged Number

//--- method 1: sort and swap
class Solution {
public:
    using ll = long long;
    long long smallestNumber(long long num) {
        ll res = 0;
        string str = to_string(abs(num));
        sort(str.begin(), str.end(), [&num](const char &a, const char &b) {
            return num < 0 ? a > b : a < b;
        });
        if (num > 0) {
            int i = 0;
            while (i < str.size() && str[i] == '0') {
                ++i;
            }
            if (i && i < str.size()) {
                swap(str[0], str[i]);
            }
        }
        for (auto &ch: str) {
            res = res*10 + (ch-'0');
        }
        return num < 0 ? -res : res;
    }
};