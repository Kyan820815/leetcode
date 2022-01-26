//--- Q: 1111. Maximum Nesting Depth of Two Valid Parentheses Strings

//--- method 1: one time pass
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size(), left = 0;
        vector<int> res(n);
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                ++left;
                res[i] = left&1;
            } else {
                res[i] = left&1;
                --left;
            }
        }
        return res;
    }
};