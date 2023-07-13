//--- Q: 0116. Populating Next Right Pointers in Each Node 
//--- last written: 2023/07/13

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

//--- method 1: link left to right
class Solution {
public:
    Node* connect(Node* root) {
        Node *now = root, *head = nullptr, *last = nullptr;
        while (now) {
            if (now->left) {
                if (!head) {
                    head = now->left;
                }
                if (last) {
                    last->next = now->left;
                }
                last = now->right;
                now->left->next = now->right;
            }
            now = now->next;
            if (!now) {
                now = head;
                head = last = NULL;
            }
        }
        return root;
    }
};

