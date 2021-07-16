//--- Q: 0331. Verify Preorder Serialization of a Binary Tree

//--- method 1: one pass
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int cnt = 1;
        for (int i = 0; i <= preorder.size(); ++i) {
            if (i == preorder.size() || preorder[i] == ',') {
                if (!cnt) {
                    return false;
                }
                cnt += preorder[i-1] == '#' ? -1 : 1;
            }
        }
        return !cnt;
    }
};