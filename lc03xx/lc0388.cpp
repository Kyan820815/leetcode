//--- Q: 0388. Longest Absolute File Path

//--- method 1: stack operation
class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0, len = 0, tcnt, hasdot;
        vector<int> sk;
        string str = "";
        for (int i = 0; i < input.size();) {
            if (input[i] == '\n') {
                tcnt = 0;
                for (++i, tcnt = 0; input[i] == '\t'; ++tcnt, ++i);
                for (; sk.size() > tcnt;) {
                    len -= sk.back();
                    sk.pop_back();
                }
            } else {
                for (hasdot = 0; i < input.size() && input[i] != '\n'; ++i) {
                    hasdot += input[i] == '.';
                    str += input[i];
                }
                sk.push_back(str.size()+1);
                len += str.size()+1;
                str = "";
                if (hasdot) {
                    res = max(res, len-1);
                }
            }
        }
        return res;
    }
};