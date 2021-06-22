//--- Q: 1869. Longer Contiguous Segments of Ones than Zeros

//--- method 1: two pointer
class Solution {
public:
    bool checkZeroOnes(string s) {
        int max_one = 0, max_zero = 0, left = 0, right = 0;
        while (right < s.size()) {
            while (s[left] != s[right]) {
                ++left;
            }
            if (s[left] == '0') {
                max_zero = max(max_zero, right-left+1);
            } else {
                max_one = max(max_one, right-left+1);
            }
            ++right;
        }
        return max_one > max_zero;
    }
};