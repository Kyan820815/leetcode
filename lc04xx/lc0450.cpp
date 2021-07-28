//--- Q: 0450. Delete Node in a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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

//--- method 1: iteration deletion
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        int dir = 0;
        auto dummy = new TreeNode(-1), parent = dummy;
        dummy->left = root;
        while (root) {
            if (root->val < key) {
                dir = 1;
                parent = root;
                root = root->right;
            } else if (root->val > key) {
                dir = 0;
                parent = root;
                root = root->left;
            } else {
                TreeNode *new_node;
                if (!root->left) {
                    new_node = root->right;
                } else if (!root->right) {
                    new_node = root->left;
                } else {
                    auto now = root->right;
                    while (now->left) {
                        now = now->left;
                    }
                    now->left = root->left;
                    new_node = root->right;
                }
                if (dir) {
                    parent->right = new_node;
                } else {
                    parent->left = new_node;
                }
                break;
            }
        }
        return dummy->left;
    }
};

//--- method 2: balanced deletion with recursion
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        int dir = 0;
        auto dummy = new TreeNode(-1), parent = dummy;
        dummy->left = root;
        while (root) {
            if (root->val < key) {
                dir = 1;
                parent = root;
                root = root->right;
            } else if (root->val > key) {
                dir = 0;
                parent = root;
                root = root->left;
            } else {
                TreeNode *new_node;
                if (!root->left) {
                    new_node = root->right;
                } else if (!root->right) {
                    new_node = root->left;
                } else {
                    root->right = findMin(root->right, &new_node);
                    new_node->left = root->left;
                    new_node->right = root->right;
                }
                if (dir) {
                    parent->right = new_node;
                } else {
                    parent->left = new_node;
                }
                break;
            }
        }
        return dummy->left;
    }
    TreeNode *findMin(TreeNode *now, TreeNode **min) {
        if (now->left) {
            now->left = findMin(now->left, min);
            return now;
        } else {
            *min = now;
            return now->right;
        }
    }
};

//--- method 3: balanced deletion with itertion
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        int dir = 0;
        auto dummy = new TreeNode(-1), parent = dummy;
        dummy->left = root;
        while (root) {
            if (root->val < key) {
                dir = 1;
                parent = root;
                root = root->right;
            } else if (root->val > key) {
                dir = 0;
                parent = root;
                root = root->left;
            } else {
                TreeNode *new_node;
                if (!root->left) {
                    new_node = root->right;
                } else if (!root->right) {
                    new_node = root->left;
                } else {
                    auto now = root->right, p = root;
                    while (now->left) {
                        p = now;
                        now = now->left;
                    }
                    if (p == root) {
                        p->right = now->right;
                    } else {
                        p->left = now->right;
                    }
                    new_node = now;
                    new_node->left = root->left;
                    new_node->right = root->right;
                }
                if (dir) {
                    parent->right = new_node;
                } else {
                    parent->left = new_node;
                }
                break;
            }
        }
        return dummy->left;
    }
};