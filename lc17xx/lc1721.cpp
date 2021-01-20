//--- Q: 1721. Swapping Nodes in a Linked List

//--- method 1: swap value
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *n1, *n2;
        dummy->next = head;
        n1 = dummy;
        while (k--) {
            n1 = n1->next;
        }
        n2 = dummy;
        ListNode *cur = n1;
        while (cur) {
            cur = cur->next;
            n2 = n2->next;
        }
        swap(n1->val, n2->val);
        return head;
    }
};

//--- method 1-2: for loop
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *n1, *n2 = dummy, *cur = dummy;
        dummy->next = head;
        for (int i = 0; i < k || cur; ++i) {
            if (i >= k) {
                n2 = n2->next;
                if (i == k) {
                    n1 = cur;
                }
            }
            cur = cur->next;
        }
        swap(n1->val, n2->val);
        return head;
    }
};

//--- follow up: change structure
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *p1, *p2, *n1, *n2;
        dummy->next = head;
        n1 = dummy;
        while (k--) {
            p1 = n1;
            n1 = n1->next;
        }
        n2 = dummy;
        ListNode *cur = n1;
        while (cur) {
            cur = cur->next;
            p2 = n2;
            n2 = n2->next;
        }
        if (n2 == p1) {
            swap(p1, p2);
            swap(n1, n2);
        }
        ListNode *tmp = n2->next;
        p1->next = n2;
        if (n1 == p2) {
            n2->next = n1;
        } else {
            n2->next = n1->next;
            p2->next = n1;
        }
        n1->next = tmp;
        return dummy->next;
    }
};