//--- Q: 430. Flatten a Multilevel Doubly Linked List

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
        Node *cur = head, *last, *next;

        while(cur)
        {
            if (cur->child)
            {
                next = cur->next;
                last = cur->child;
                while (last->next)
                    last = last->next;
                last->next = next;
                if (next) next->prev = last;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
            }
            cur = cur->next;
        }
        return head;
    }
};

//--- method 2: stack operation
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node *> sk;
        Node *dummy = new Node(-1, NULL, head, NULL), *cur, *pre;
        cur = head, pre = dummy;

        while(cur || sk.size())
        {
            if (cur->child)
            {
                if (cur->next) sk.push(cur->next);
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
            }
            pre = cur;
            cur = cur->next;

            if (!cur && sk.size())
            {
                cur = sk.top();
                pre->next = cur;
                cur->prev = pre;
                sk.pop();
            }
        }
        return head;
    }
};