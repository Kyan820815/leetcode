//--- Q: 0117. Populating Next Right Pointers in Each Node II

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

//--- method 1: O(1) space traversal and connect
class Solution {
public:
    Node* connect(Node* root) {
        Node *now = root, *head = nullptr, *rear = nullptr;
        while (now) {
            if (now->left) {
                if (!head) {
                    head = rear = now->left;
                } else {
                    rear->next = now->left;
                    rear = now->left;
                }
            }
            if (now->right) {
                if (!head) {
                    head = rear = now->right;
                } else {
                    rear->next = now->right;
                    rear = now->right;
                }
            }
            now = now->next;
            if (!now) {
                now = head;
                head = rear = nullptr;
            }
        }
        return root;
    }
};