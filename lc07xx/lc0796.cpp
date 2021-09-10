//--- Q: 0796. Rotate String

//--- method 1: combine two A and check B in it
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        string str = s + s;
        for (int i = 0; i < s.size(); ++i) {
            int j;
            for (j = 0; j < goal.size(); ++j) {
                if (str[i+j] != goal[j]) {
                    break;
                }
            }
            if (j == goal.size()) {
                return true;
            }
        }
        return false;
    }
};