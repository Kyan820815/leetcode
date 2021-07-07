//--- Q: 0143. Reorder List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: better solution
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = slow->next, *revH = nullptr;
        slow->next = NULL;
        while (cur) {
            auto tmp = cur->next;
            cur->next = revH;
            revH = cur;
            cur = tmp;
        }
        auto left = head, right = revH;
        while (left && right) {
            auto nleft = left->next, nright = right->next;
            left->next = right;
            right->next = nleft;
            left = nleft, right = nright;
        }
    }
};