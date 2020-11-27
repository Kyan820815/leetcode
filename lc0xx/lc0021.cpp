//--- Q: 021. Merge Two Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //--- method 1: divide & conquer
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL, *rear, *cur;

        while(l1 != NULL && l2 != NULL)
        {
        	if (l1->val < l2->val)
        	{
        		cur = new ListNode(l1->val);
        		l1 = l1->next;
        	}
        	else
        	{
        		cur = new ListNode(l2->val);
        		l2 = l2->next;
        	}
        	if (l3 == NULL) l3 = rear = cur;
        	else
        	{
        		rear->next = cur;
        		rear = cur;
        	}
        }
        while(l1 != NULL)
        {
        	cur = new ListNode(l1->val);
        	if (l3 == NULL) l3 = rear = cur;
        	else
        	{
        		rear->next = cur;
        		rear = cur;
        	}
        	l1 = l1->next;
        }
        while(l2 != NULL)
        {
        	cur = new ListNode(l2->val);
        	if (l3 == NULL) l3 = rear = cur;
        	else
        	{
        		rear->next = cur;
        		rear = cur;
        	}
        	l2 = l2->next;
        }
        return l3;
    }
};

//--- method 2: recursive solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val <= l2->val)
        {
        	l1->next = mergeTwoLists(l1->next, l2);
        	return l1;
        }
        else
        {
        	l2->next = mergeTwoLists(l1, l2->next);
        	return l2;
        }
    }
};