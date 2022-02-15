//--- Q: 1963. Minimum Number of Swaps to Make the String Balanced

//--- method 1: two pointers
class Solution {
public:
    int minSwaps(string s) {
        int left = 0, right = s.size()-1, res = 0, cnt = 0;
        while (left < right) {
            cnt += s[left++] == '[' ? 1 : -1;
            if (cnt < 0) {
                while (s[right] == ']') {
                    --right;
                }
                cnt = 1;
                ++res;
            }
        }
        return res;
    }
};