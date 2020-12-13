//--- Q: 1666. Change the Root of a Binary Tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

//--- method 1: recursion
class Solution {
public:
    Node *old_root;
    Node* flipBinaryTree(Node* root, Node * leaf) {
        old_root = root;
        return reroot(leaf, NULL);
    }
    Node *reroot(Node *now, Node *new_parent) {
        Node *old_parent = now->parent;
        now->parent = new_parent;
        if (now->left == new_parent) {
            now->left = NULL;
        } else {
            now->right = NULL;
        }
        if (now == old_root) {
            return now;
        }
        if (now->left) {
            swap(now->left, now->right);
        }
        now->left = reroot(old_parent, now);
        return now;
    }
};