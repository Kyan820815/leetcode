//--- Q: 0160. Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- meathod 1: finish own list then process other list (good)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto na = headA, nb = headB;
        while (na != nb) {
            na = na->next;
            nb = nb->next;
            if (na == nb) {
                break;
            }
            if (!na) {
                na = headB;
            }
            if (!nb) {
                nb = headA;
            }
        }
        return na;
    }
};