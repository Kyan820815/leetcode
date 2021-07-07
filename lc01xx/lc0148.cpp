//--- Q: 0148. Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: divide and conquer, better
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return dfs(head, nullptr);
    }
    ListNode *dfs(ListNode *head, ListNode *rear) {
        if (head == rear) {
            return head;
        }
        auto slow = head, fast = head;
        while (fast != rear && fast->next != rear) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto rhead = slow->next;
        slow->next = NULL;
        auto left = dfs(head, slow);
        auto right = dfs(rhead, rear);
        return merge(left, right);
    }
    ListNode *merge(ListNode *l1, ListNode *l2) {
        auto dummy = new ListNode(-1), cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

//--- method 2: bottom up O(1) space O(nlogn) time
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int len = 0;
        ListNode *dummy = new ListNode(-1, head), *cur = head;
        while (cur) {
            cur = cur->next;
            ++len;
        }
        cur = head;
        for (int i = 1; i < len; i*=2) {
            auto last = dummy, cur = dummy->next;
            while (cur) {
                auto left = cur;
                auto right = findnext(left, i);
                if (right) {
                }
                auto next_left = findnext(right, i);
                last = merge(left, right, last);
                cur = next_left;
            }
        }
        return dummy->next;
    }
    ListNode *findnext(ListNode *cur, int sz) {
        for (int i = 1; i < sz && cur; ++i) {
            cur = cur->next;
        }
        if (!cur) {
            return nullptr;
        }
        auto rtn_node = cur->next;
        cur->next = nullptr;
        return rtn_node;
    }
    ListNode *merge(ListNode *l1, ListNode *l2, ListNode *last) {
        auto cur = last;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        while (cur->next) {
            cur = cur->next;
        }
        return cur;
    }
};