//--- Q: 0083. Remove Duplicates from Sorted List
//--- last written: 2023/07/08

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

//--- method 1: delete duplicate number
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head), *pre = dummy, *cur = head;
        dummy->next = head;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                while (cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                pre->next = cur;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};
