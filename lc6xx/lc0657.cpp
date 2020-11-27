//--- Q: 657. Robot Return to Origin

//--- method 1: O(n) one time pass
class Solution {
public:
    bool judgeCircle(string moves) {
        int res = 0;
        for (auto &s: moves) {
            switch (s) {
                case 'U':
                    ++res;
                    break;
                case 'D':
                    --res;
                    break;
                case 'L':
                    res += 2;
                    break;
                case 'R':
                    res -= 2;
                    break;
                default:
                    return false;
            }
        }
        return !res;
    }
};