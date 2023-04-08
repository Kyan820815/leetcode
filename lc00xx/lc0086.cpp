//--- Q: 0086. Partition List
//--- last written: 2023/04/05

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: maintian 1 list and original list
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(-1), *c1 = dummy1;
        ListNode *dummy2 = new ListNode(-1), *c2 = dummy2;
        ListNode *cur = head;
        while (cur) {
            if (cur->val < x) {
                c1->next = cur;
                c1 = cur;
            } else {
                c2->next = cur;
                c2 = cur;
            }
            cur = cur->next;
        }
        c2->next = NULL;
        c1->next = dummy2->next;
        return dummy1->next;
    }
};
