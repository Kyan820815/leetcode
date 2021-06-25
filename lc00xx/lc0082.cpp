//--- Q: 082. Remove Duplicates from Sorted List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: delete duplicate number
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *prev = dummy, *now = head;
        dummy->next = head; 
        while (now) {
            while (now->next && now->val == now->next->val) {
                now = now->next;
            }
            if (prev->next != now) {
                prev->next = now->next;
            } else {
                prev = now;
            }
            now = now->next;
        }
        return dummy->next;
    }
};