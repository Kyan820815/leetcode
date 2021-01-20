//--- Q: 1290. Convert Binary Number in a Linked List to Integer

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

//--- method 1: linear pass and bit manipulation
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *now = head;
        int val = 0;
        while (now) {
            val = (val << 1) | now->val;
            now = now->next;
        }
        return val;
    }
};