//--- Q: 1496. Path Crossing

//--- method 1: set
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> set;
        set.insert("0,0");
        int x = 0, y = 0;
        for (auto &c: path) {
            if (c == 'N') {
                ++y;
            } else if (c == 'S') {
                --y;
            } else if (c == 'E') {
                ++x;
            } else {
                --x;
            }
            string str = to_string(x)+","+to_string(y);
            if (set.find(str) != set.end()) {
                return true;
            }
            set.insert(str);
        }
        return false;
    }
};