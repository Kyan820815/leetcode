//--- Q: 1474. Delete N Nodes After M Nodes of a Linked List

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

//--- method 1: clean code
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1), *now = dummy;
        dummy->next = head;
        while (now) {
            for (int i = 0; i < m+n&&now; ++i) {
                if (i < m) {
                    now = now->next;
                } else if (now->next) {
                    now->next = now->next->next;
                }
            }
        }
        return head;
    }
};

//--- method 2: my version
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        int first, second;
        ListNode *now = head;
        while (1) {
            first = m-1;
            while (now && first) {
                now = now->next;
                --first;
            }
            if (!now) {
                break;
            }
            second = n;
            ListNode *next_node = now;
            while (next_node && second) {
                next_node = next_node->next;
                --second;
            }
            if (!next_node) {
                now->next = NULL;
                break;
            } else {
                now->next = next_node->next;
                now = now->next;
            }
        }
        return head;
    }
};
