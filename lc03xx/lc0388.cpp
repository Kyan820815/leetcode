//--- Q: 388. Longest Absolute File Path

//--- method 1: stack operation
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> sk;
        int i = 0, tcnt = 0, dotcnt = 0, sum = 0, res = 0;
        string str = "";
        while (i <= input.size()) {
            if (i == input.size() || input[i] == '\n') {
                while (sk.size() > tcnt) {
                    sum -= sk.back();
                    sk.pop_back();
                }
                if (dotcnt) {
                    res = max(res, (int)str.size()+sum);
                } else {
                    sk.push_back(str.size()+1);
                    sum += str.size()+1;
                }
                str = "", tcnt = 0, dotcnt = 0, ++i;
            } else if (input[i] == '\t') {
                ++tcnt, ++i;
            } else {
                if (input[i] == '.') {
                    ++dotcnt;
                }
                str.push_back(input[i++]);
            }
        }
        
        return res;
    }
};