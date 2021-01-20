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
        Node *now = head;
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
        } else {
            while (!(now->val <= insertVal && insertVal <= now->next->val 
                     || now->val > now->next->val && (now->val <= insertVal || insertVal <= now->next->val) 
                     || now->next == head)) {
                now = now->next;
            }
            Node *tmp = now->next;
            now->next = new Node(insertVal);
            now->next->next = tmp;
        }
        return head;
    }
};