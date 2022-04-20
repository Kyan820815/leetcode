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

//--- method 2: morris traversal
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        dummy = new TreeNode(-1), cur = dummy;
        future = root;
        while (future) {
            if (future->left) {
                auto prev = future;
                future = future->left;
                while (future->right) {
                    future = future->right;
                }
                future->right = prev;
                future = prev->left;
            } else {
                break;
            }
        }
    }
    
    bool hasNext() {
        return future || cur->right != nullptr;
    }
    
    int next() {
        if (cur->right && cur->right != future) {
            cur = cur->right;
            return cur->val;
        }
        while (future) {
            if (future->left) {
                auto prev = future;
                future = future->left;
                while (future->right && future->right != prev) {
                    future = future->right;
                }
                if (future->right == prev) {
                    prev->left = cur;
                    cur = prev;
                    future = prev->right;
                    break;
                } else {
                    future->right = prev;
                    future = prev->left;
                }
            } else {
                cur->right = future;
                future->left = cur;
                cur = future;
                future = future->right;
                break;
            }
        }
        return cur->val;
    }
    
    bool hasPrev() {
        return cur != dummy && cur->left != dummy;
    }
    
    int prev() {
        cur = cur->left;
        return cur->val;
    }
    
    TreeNode *future, *cur, *dummy;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */