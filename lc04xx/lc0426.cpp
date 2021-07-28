//--- Q: 0426. Convert Binary Search Tree to Sorted Doubly Linked List

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

//--- method 1: moris traversal
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node *now = root, *last = nullptr, *head = nullptr;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = now->left;
                while (now->right && now->right != prev) {
                    now = now->right;
                }
                if (now->right) {
                    if (last) {
                        prev->left = last;
                    }
                    last = prev;
                    now = prev->right;
                } else {
                    now->right = prev;
                    now = prev->left;
                }
            } else {
                if (!head) {
                    head = now;
                }
                if (last) {
                    last->right = now;
                    now->left = last;
                }
                last = now;
                now = now->right;
            }
        }
        if (head) {
            last->right = head;
            head->left = last;
        }
        return head;
    }
};