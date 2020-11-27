//--- Q: 255. Verify Preorder Sequence in Binary Search Tree

//--- method 1: O(1) space
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minv = INT_MIN, j = -1;
        for (int i = 0; i < preorder.size(); ++i) {
            if (minv > preorder[i]) {
                return false;
            }
            while (j >= 0 && preorder[j] < preorder[i]) {
                minv = preorder[j--];
            }
            preorder[++j] = preorder[i];
        }
        return true;
    }
};

//--- method 2: O(n) space
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        vector<int> sk;
        int minv = INT_MIN;
        for (int i = 0; i < preorder.size(); ++i) {
            if (minv > preorder[i]) {
                return false;
            }
            while (sk.size() && sk.back() < preorder[i]) {
                minv = sk.back();
                sk.pop_back();
            }
            sk.push_back(preorder[i]);
        }
        return true;
    }
};