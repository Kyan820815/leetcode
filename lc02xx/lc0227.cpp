//--- Q: 0227. Basic Calculator II

//--- method 1: two pass check with stack, space: O(n)
class Solution {
public:
    int calculate(string s) {
        vector<int> sk;
        int cur_sum = 0;
        char lastop = '+';
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (i == s.size() || !isdigit(s[i])) {
                if (lastop == '+') {
                    sk.push_back(cur_sum);
                } else if (lastop == '-') {
                    sk.push_back(-cur_sum);
                } else if (lastop == '*') {
                    sk.back() *= cur_sum;
                } else {
                    sk.back() /= cur_sum;
                }
                cur_sum = 0, lastop = s[i];
            } else {
                cur_sum = cur_sum*10 + (s[i]-'0');
            }
        }
        int total = 0;
        for (auto &num: sk) {
            total += num;
        }
        return total;
    }
};