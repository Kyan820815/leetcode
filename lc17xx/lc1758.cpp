//--- Q: 1758. Minimum Changes To Make Alternating Binary String

//--- method 1: find error position
class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), ones = 0, zeros = 0;
        for (int i = 0; i < n; ++i) {
            ones += i&1 ? s[i] != '1' : s[i] != '0';
        }
        return min(ones, n-ones);
    }
};