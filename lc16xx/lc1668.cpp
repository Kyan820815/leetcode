//--- Q: 1668. Maximum Repeating Substring

//--- method 1: find max k by add word to tmp k times
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int cnt = 0;
        string tmp = word;
        while (sequence.find(tmp) != string::npos) {
            ++cnt;
            tmp += word;
        }
        return cnt;
    }
};