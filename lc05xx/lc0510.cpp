//--- Q: 510. Inorder Successor in BST II

//--- method 1: BST traversal
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node *now = node, *r = node;
        if (node->right) {
            node = node->right;
            while (node->left)
                node = node->left;
            return node;
        } else {
            while (node->parent) {
                Node *tmp = node->parent;
                if (tmp->left == node)
                    return tmp;
                node = tmp;
            }
        }
        return NULL;
    }
};