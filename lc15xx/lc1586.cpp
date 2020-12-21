//--- Q: 1586. Binary Search Tree Iterator II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//--- method 1: stack traversal and list linking
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    bool hasNext() {
        return cur->right || sk.size();
    }
    
    int next() {
        if (!cur->right) {
            TreeNode *next = sk.back();
            sk.pop_back();
            pushLeft(next->right);
            next->right = NULL;
            cur->right = next;
            next->left = cur;
        }
        cur = cur->right;
        return cur->val;
    }
    
    bool hasPrev() {
        return cur != dummy && cur->left != dummy;
    }
    
    int prev() {
        cur = cur->left;
        return cur->val;
    }
    
    void pushLeft(TreeNode *now) {
        while (now) {
            sk.push_back(now);
            now = now->left;
        }
    }
    TreeNode *dummy = new TreeNode(-1), *cur = dummy;
    vector<TreeNode *> sk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */