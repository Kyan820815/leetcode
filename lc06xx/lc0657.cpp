//--- Q: 0657. Robot Return to Origin

//--- method 1: O(n) one time pass
class Solution {
public:
    bool judgeCircle(string moves) {
        int hor = 0, ver = 0;
        for (auto &ch: moves) {
            if (ch == 'L') {
                --hor;
            } else if (ch == 'R') {
                ++hor;
            } else if (ch == 'U') {
                --ver;
            } else {
                ++ver;
            }
        }
        return !hor && !ver;
    }
};