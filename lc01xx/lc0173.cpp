//--- Q: 0173. Binary Search Tree Iterator

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: stack iteration
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            sk.push_back(root);
            root = root->left;
        }
    }
    
    int next() {
        auto now = sk.back();
        sk.pop_back();
        int val = now->val;
        now = now->right;
        if (now) {
            while (now) {
                sk.push_back(now);
                now = now->left;
            }
        }
        return val;
    }
    
    bool hasNext() {
        return sk.size();
    }
    vector<TreeNode *> sk;
};

//--- method 2: moris traversal
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        now = root;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = now->left;
                while (now->right) {
                    now = now->right;
                }
                now->right = prev;
                now = prev->left;
            } else {
                break;
            }
        }
    }
    
    int next() {
        int val;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = now->left;
                while (now->right && now->right != prev) {
                    now = now->right;
                }
                if (now->right) {
                    val = prev->val;
                    now->right = NULL;
                    now = prev->right;
                    break;
                } else {
                    now->right = prev;
                    now = prev->left;
                }
            } else {
                val = now->val;
                now = now->right;
                break;
            }
        }
        return val;
    }
    
    bool hasNext() {
        return now != nullptr;
    }
    TreeNode *now;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */