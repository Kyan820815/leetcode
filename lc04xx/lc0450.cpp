//--- Q: 450. Delete Node in a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key)
    	{
    		TreeNode *now;
            if (!root->left && !root->right) return NULL;
            else if (!root->left || !root->right)
                return (root->left) ? root->left : root->right;
            else
            {
                now = root->left;
                while (now->right)
                    now = now->right;
                now->right = root->right;
                return root->left;
            }
    	}
    	else if (root->val < key)
    		root->right = deleteNode(root->right, key);
    	else if (root->val > key)
    		root->left = deleteNode(root->left, key);
    	return root;
    }
};

//--- method 1-2: recursion
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return NULL;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->right) {
                TreeNode *min;
                root->right = findMin(root->right, &min);
                min->left = root->left;
                min->right = root->right;
                root->left = NULL;
                root->right = NULL;
                delete(root);
                return min;
            } else {
                return root->left;
            }
        }
        return root;
    }
    TreeNode *findMin(TreeNode *root, TreeNode **min) {
        if (root->left) {
            root->left = findMin(root->left, min);
            return root;
        } else {
            *min = root;
            return root->right;
        }
    }
};

//--- method 2: iteration
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *now = root, *dummy = new TreeNode(-1);
        dummy->left = root;
        TreeNode *p = dummy;
        int dir = 0;
        while (now) {
            if (now->val < key) {
                dir = 1;
                p = now;
                now = now->right;
            } else if (now->val > key) {
                dir = 0;
                p = now;
                now = now->left;
            } else {
                TreeNode *node;
                if (now->left) {
                    node = now->left;
                    TreeNode *cur = now->left;
                    while (cur->right)
                        cur = cur->right;
                    cur->right = now->right;
                } else {
                   node = now->right;
                }
                if (!dir) {
                    p->left = node;
                } else {
                    p->right = node;
                }
                return dummy->left;
            }
        }
        return dummy->left;
    }
};
