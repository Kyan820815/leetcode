//--- Q: 388. Longest Absolute File Path

//--- method 1: stack operation
class Solution {
public:
    int len = 0, depth = 0;
    vector<string> sk;
    int lengthLongestPath(string input) {
        int maxv = 0;
        for (int i = 0; i < input.size();) {
            if (input[i] == '\t') {
                depth = 0;
                while (i < input.size() && input[i] == '\t') {
                    ++i, ++depth;
                }
                pop_stack();
            } else if (input[i] == '\n'){
                ++i;                
            } else {
                string str = "";
                while (isalpha(input[i]) || isdigit(input[i]) || input[i] == '.' || input[i] == ' ') {
                    str += input[i++];
                }
                pop_stack();
                len += str.size();
                sk.push_back(str);
                len += sk.size() > 1;
                if (str.find(".") != string::npos && len > maxv) {
                    maxv = len;
                }
                depth = 0;
            }
        }
        return maxv;
    }
    void pop_stack() {
        while (sk.size() && depth != sk.size()) {
            len -= sk.back().size();
            len -= sk.size() > 1;
            sk.pop_back();
        }
    }
};