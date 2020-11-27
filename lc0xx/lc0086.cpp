//--- Q: 086. Partition List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: maintian 1 list and original list
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left_head, *left_tail, *right_head;
        ListNode *cur, *pre;
        left_head = left_tail = right_head = pre = NULL;

        cur = head;
        while(cur)
        {
            if (cur->val < x)
            {
                if (!left_head)
                    left_head = left_tail = cur;
                else
                {
                    left_tail->next = cur;
                    left_tail = cur;
                }
                if (pre)
                    pre->next = cur->next;
            }
            else if (cur->val >= x)
            {
                if (!right_head) right_head = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        if (left_tail)
            left_tail->next = right_head;
        return left_head ? left_head : right_head;
    }
};

//--- method 2: maintian 2 lists
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left_head, *left_tail, *right_head, *right_tail;
        ListNode *cur;
        left_head = left_tail = right_head = right_tail = NULL;

        cur = head;
        while(cur)
        {
        	if (cur->val < x)
        	{
        		if (!left_head)
        			left_head = left_tail = cur;
        		else
        		{
        			left_tail->next = cur;
        			left_tail = cur;
        		}
        	}
        	else if (cur->val >= x)
        	{
        		if (!right_head)
        			right_head = right_tail = cur;
        		else
        		{
        			right_tail->next = cur;
        			right_tail = cur;
        		}
        	}
        	cur = cur->next;
        }
        if (left_tail)
        	left_tail->next = right_head;
        if (right_tail)
        	right_tail->next = NULL;
        return left_head ? left_head : right_head;
    }
};