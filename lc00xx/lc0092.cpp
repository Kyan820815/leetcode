//--- Q: 092. Reverse Linked List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1-1: I think the best solution
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy, *now = head;
        pre->next = head;
        for (int i = 1; i < m; ++i)
        {
            pre = now;
            now = now->next;
        }
        ListNode *cur = now->next, *last = now;
        ListNode *next_node;
        for (int i = 1; i <= n-m; ++i)
        {
            next_node = cur->next;
            cur->next = last;
            last = cur;
            cur = next_node;
        }
        pre->next = last;
        now->next = cur;
        return dummy->next;
    }
};

//--- method 1-2: one pass, new version
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tmp, *end, *cur, *prev, *rev;
        dummy->next = head;
        prev = dummy;
        cur = head;
        for (int i = 1; i < m; ++i)
        {
            prev = cur;
            cur = cur->next;
        }
        rev = NULL;
        for (int i = m; i <= n; ++i)
        {
            tmp = cur;
            cur = cur->next;
            tmp->next = rev;
            rev = tmp;
            if (i == m)
            {
                end = rev;
            }
        }

        prev->next = rev;
        end->next = cur;
        return dummy->next;
    }
};

//--- method 1-3: one pass
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy, *left, *right, *now, *rev = NULL;
		dummy->next = head;
		for (int i = 1; i < m; ++i)
			cur = cur->next;
		left = cur;
		cur = cur->next;
		for (int i = m; i <= n; ++i)
		{
			now = cur;
			cur = cur->next;
			if (!rev)
			{
				rev = now;
				right = rev;
			}
			else
			{
				now->next = rev;
				rev = now;
			}
		}
		right->next = cur;
		left->next = rev;
		return dummy->next;
    }
};