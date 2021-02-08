//--- Q: 1598. Crawler Log Folder

//--- method 1: check symbol
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int sk = 0;
        for (auto &log: logs) {
            if (log == "../") {
                sk -= (sk > 0);
            } else if (log != "./") {
                ++sk;
            }
        }
        return sk;
    }
};