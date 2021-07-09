//--- Q: 0206. Reverse Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *revH = nullptr, *cur = head;
        while (cur) {
            auto tmp = cur->next;
            cur->next = revH;
            revH = cur;
            cur = tmp;
        }
        return revH;
    }
};