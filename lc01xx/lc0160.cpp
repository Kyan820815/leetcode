//--- Q: 160. Intersection of Two Linked Lists

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
        ListNode *curA, *curB;
        
        if (headA == NULL || headB == NULL)
            return NULL;
        
        curA = headA;
        curB = headB;
        
        while(curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
            
            if (curA == curB)
                return curA;
            
            if (curA == NULL)
                curA = headB;
            if (curB == NULL)
                curB = headA;
        }
        return curA;
    }
};

//--- meathod 2: move pointer of longer list in the distance of length difference(A,B) (good)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA, *curB;
        int a_len = 0, b_len = 0;
        int diff;

        curA = headA;
        curB = headB;

        while(curA != NULL || curB != NULL)
        {
        	if (curA != NULL)
        	{
        		curA = curA->next;
        		a_len++;
        	}
        	if (curB != NULL)
        	{
        		curB = curB->next;
        		b_len++;
        	}
        }

        curA = headA;
        curB = headB;

        if (a_len >= b_len)
        {
        	diff = a_len-b_len;
        	while(diff > 0)
        	{
        		curA = curA->next;
        		diff--;
        	}
        }
        else
        {
        	diff = b_len-a_len;
        	while(diff > 0)
        	{
        		curB = curB->next;
        		diff--;
        	}
        }
        
        while(curA != curB)
        {
    		curA = curA->next;
    		curB = curB->next;
        }
        return NULL;
    }
};