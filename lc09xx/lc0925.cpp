//--- Q: 0925. Long Pressed Name

//--- method 1: double pointer
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.size()) {
            if (name[i] == typed[j]) {
                ++i;
            } else if (j && typed[j] == typed[j-1]);
            else {
                return false;
            }
            ++j;
        }
        return i == name.size();
    }
};