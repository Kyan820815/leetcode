//--- Q: 426. Convert Binary Search Tree to Sorted Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

//--- method 1: inorder recursion
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node *first = NULL, *last = NULL, *cur_last = NULL;
        inorder(root, &first, &cur_last, &last);
        first->left = last;
        last->right = first;
        return first;
    }
    void inorder(Node *node, Node **first, Node **cur_last, Node **last) {
        if (node->left)
            inorder(node->left, first, cur_last, last);
        
        if (*first) {
            (*cur_last)->right = node;
            node->left = *cur_last;
        } else
            *first = node;
        *cur_last = *last = node;
        
        if (node->right)
            inorder(node->right, first, cur_last, last);
    }
};

//--- method 2: moris traversal
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return NULL;
        }
        Node *now = root, *last = NULL, *nh = NULL;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = now->left;
                while (now->right && now->right != prev) {
                    now = now->right;
                }
                if (!now->right) {
                    now->right = prev;
                    now = prev->left;
                } else {
                    if (last) {
                        prev->left = last;
                    }
                    last = prev;                    
                    now = prev->right;
                }
            } else {
                if (last) {
                    last->right = now;
                    now->left = last;
                }
                if (!nh) {
                    nh = now;
                }
                last = now;
                now = now->right;
            }
        }
        last->right = nh;
        nh->left = last;
        return nh;        
    }
};