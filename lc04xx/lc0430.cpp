//--- Q: 0430. Flatten a Multilevel Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

//--- method 1: link directly
class Solution {
public:
    Node* flatten(Node* head) {
        auto now = head;
        while (now) {
            if (now->child) {
                auto cur = now->child;
                while (cur->next) {
                    cur = cur->next;
                }
                cur->next = now->next;
                if (now->next) {
                    now->next->prev = cur;
                }
                now->next = now->child;
                now->child->prev = now;
                now->child = nullptr;
            }
            now = now->next;
        }
        return head;
    }
};