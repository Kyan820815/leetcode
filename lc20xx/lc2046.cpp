//--- Q: 2046. Sort Linked List Already Sorted Using Absolute Values

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

//--- method 1: linear operation
class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        auto prev = head, cur = head->next;
        while (cur) {
            if (cur->val < 0) {
                prev->next = cur->next;
                cur->next = head;
                head = cur;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};