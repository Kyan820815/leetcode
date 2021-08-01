//--- Q: 0510. Inorder Successor in BST II

//--- method 1: BST traversal
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        } else {
            while (node->parent && node->parent->right == node) {
                node = node->parent;
            }
            return node->parent;
        }
    }
};

//--- follow up:
class Solution {
public:
    Node* inorderPredecessor(Node* node) {
        if (node->left) {
            node = node->left;
            while (node->right) {
                node = node->right;
            }
            return node;
        } else {
            while (node->parent && node->parent->left == node) {
                node = node->parent;
            }
            return node->parent;
        }
    }
};