//--- Q: 0328. Odd Even Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: one pass O(n), better
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddhead = new ListNode(-1), *evenhead = new ListNode(-1);
        ListNode *ocur = oddhead, *ecur = evenhead, *cur = head;
        while (cur) {
            ocur->next = cur;
            ocur = cur;
            cur = cur->next;
            if (!cur) {
                break;
            }
            ecur->next = cur;
            ecur = cur;
            cur = cur->next;
        }
        ocur->next = evenhead->next;
        ecur->next = nullptr;
        return oddhead->next;
    }
};