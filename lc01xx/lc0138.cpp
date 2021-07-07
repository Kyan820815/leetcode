//--- Q: 0138. Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

//--- method 1: copy link, better
class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto now = head;
        while (now) {
            auto tmp = now->next;
            now->next = new Node(now->val);
            now->next->next = tmp;
            now = tmp;
        }
        now = head;
        while (now) {
            if (now->random) {
                now->next->random = now->random->next;
            }
            now = now->next->next;
        }
        auto dummy = new Node(-1), cur = dummy;
        now = head;
        while (now) {
            cur->next = now->next;
            now->next = now->next->next;
            cur = cur->next;
            now = now->next;
        }
        return dummy->next;
    }
};