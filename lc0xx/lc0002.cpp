//--- Q: 002. Add Two Numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: digit by digit add
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1, *cur2, *cur3;
        ListNode *head3, *add, *left;
        int rem = 0;
        
        cur1 = l1, cur2 = l2;
        head3 = NULL;
        while(cur1 != NULL && cur2 != NULL)
        {
        	rem = rem + (cur1->val + cur2->val);
        	add = new ListNode(rem%10);
        	if (head3 == NULL)
        		head3 = cur3 = add;
        	else
        	{
        		cur3->next = add;
        		cur3 = add;
        	}
        	rem = rem / 10;
        	cur1 = cur1->next;
        	cur2 = cur2->next;
        }

        left = (cur1 != NULL) ? cur1 : cur2;
        while(left != NULL)
        {
        	rem = rem + left->val;
        	add = new ListNode(rem%10);
       		cur3->next = add;
       		cur3 = add;
        	rem = rem / 10;
        	left = left->next;
        }

        if (rem != 0)
        {
        	add = new ListNode(rem);
       		cur3->next = add;
       		cur3 = add;
        }

        return head3;
    }
};