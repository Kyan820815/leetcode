//--- Q: 1669. Merge In Between Linked Lists

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

//--- method 1: linear pass
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *n1 = list1;
        --a;
        b -= a;
        while (a--) {
            n1 = n1->next;
        }
        ListNode *n2 = n1;
        while (b--) {
            n2 = n2->next;
        }
        ListNode *cur = list2;
        while (cur->next) {
            cur = cur->next;
        }
        n1->next = list2, cur->next = n2->next;
        return list1;
    }
};