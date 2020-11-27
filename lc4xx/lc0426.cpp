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
            return root;
        }
        Node *head = NULL, *now = root, *pre = NULL;
        while (now) {
            if (now->left) {
                Node *parent = now;
                now = now->left;
                while (now->right && now->right != parent) {
                    now = now->right;
                }
                if (!now->right) {
                    now->right = parent;
                    now = parent->left;
                } else {
                    if (pre) {
                        parent->left = pre;
                    }
                    pre = parent;
                    now = parent->right;
                }
            } else {
                if (!head) {
                    head = now;
                }
                if (pre) {
                    now->left = pre;
                    pre->right = now;
                }
                pre = now;
                now = now->right;
            }
        }
        head->left = pre;
        pre->right = head;
        return head;
    }
};