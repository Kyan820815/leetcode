//--- Q: 83. Remove Duplicates from Sorted List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *now = head, *prev = dummy;
        dummy->next = head;
        while (now) {
            if (!now->next || now->next && now->val != now->next->val) {
                prev->next = now;
                prev = now;
            }
            now = now->next;
        }
        return dummy->next;
    }
};