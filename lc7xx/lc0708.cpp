//--- Q: 708. Insert into a Sorted Circular Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

//--- method 1: find the interval
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *node = new Node(insertVal);
        if (!head) {
            node->next = node;
            return node;
        }
        auto now = head;
        while (now->next != head) {
            if (now->val <= insertVal && insertVal <= now->next->val || now->next->val < now->val && (now->val <= insertVal || insertVal <= now->next->val)) {
                break;
            }
            now = now->next;
        }
        node->next = now->next;
        now->next = node;
        return head;
    }
};