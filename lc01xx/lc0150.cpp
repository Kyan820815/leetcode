//--- Q: 0150. Evaluate Reverse Polish Notation

//--- method 1: stack operation
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> sk;
        for (auto &token: tokens) {
            if (isdigit(token.back())) {
                sk.push_back(stoi(token));
            } else {
                auto second = sk.back();
                sk.pop_back();
                auto first = sk.back();
                sk.pop_back();
                if (token == "+") {
                    sk.push_back(first+second);
                } else if (token == "-") {
                    sk.push_back(first-second);
                } else if (token == "*") {
                    sk.push_back(first*second);
                } else {
                    sk.push_back(first/second);
                }
            }
        }
        return sk[0];
    }
};