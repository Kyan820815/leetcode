//--- Q: 1111. Maximum Nesting Depth of Two Valid Parentheses Strings

//--- method 1: one time pass
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> res;
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                ++depth;
            }
            res.push_back(depth % 2);
            if (seq[i] == ')') {
                --depth;
            }
        }
        return res;
    }
};