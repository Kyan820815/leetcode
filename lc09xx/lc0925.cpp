//--- Q: 925. Long Pressed Name

//--- method 1: double pointer
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int ni = 0;
        for (int i = 0; i < typed.size(); ++i) {
            if (ni < name.size() && typed[i] == name[ni]) {
                ++ni;
            } else if (i > 0 && typed[i] == typed[i-1]);
            else {
                return false;
            }
        }
        return ni == name.size();
    }
};