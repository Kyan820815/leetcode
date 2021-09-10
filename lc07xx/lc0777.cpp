//--- Q: 0777. Swap Adjacent in LR String

//--- method 1: two pointer
class Solution {
public:
    bool canTransform(string start, string end) {
        int i, j;
        for (i = 0, j = 0; i < start.size() || j < end.size(); ++i, ++j) {
            for (; i < start.size() && start[i] == 'X'; ++i);
            for (; j < end.size() && end[j] == 'X'; ++j);
            if (i == start.size() && j == end.size()) {
                break;
            }
            if (i == start.size() || j == end.size() || start[i] != end[j] || start[i] == 'R' && i > j || start[i] == 'L' && i < j) {
                return false;
            }
        }
        return true;
    }
};