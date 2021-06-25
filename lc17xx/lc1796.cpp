//--- Q: 1796. Second Largest Digit in a String

//--- method : O(1) space search
class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (auto &ch: s) {
            if (isdigit(ch)) {
                if (first == -1 || first <= (ch-'0')) {
                    if (first == ch-'0') {
                        continue;
                    }
                    second = first;
                    first = ch-'0';
                } else if (second == -1 || second < (ch-'0')) {
                    second = ch-'0';
                }
            }
        }
        return second;
    }
};