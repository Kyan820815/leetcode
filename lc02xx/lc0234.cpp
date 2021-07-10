//--- Q: 0234. Palindrome Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: O(1) space & O(n) time
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *revH = nullptr, *right = slow, *left = head;
        while (right) {
            auto tmp = right->next;
            right->next = revH;
            revH = right;
            right = tmp;
        }
        right = revH;
        while (left && right) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

//--- method 2: magic solution, O(n) space & O(n) time
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return dfs(&head, head);
    }
    bool dfs(ListNode **left, ListNode *right) {
        if (!right) {
            return true;
        }
        if (dfs(left, right->next) && (*left)->val == right->val) {
            *left = (*left)->next;
        } else {
            return false;
        }
        return true;
    }
};
