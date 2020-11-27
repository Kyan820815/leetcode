//--- Q: 148. Sort List

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
        return divide(head, NULL);
    }
    ListNode *divide(ListNode *head, ListNode *rear)
    {
    	ListNode *slow, *fast;
    	ListNode *left, *right;
    	ListNode *new_head;
    	if (head == rear)
    		return head;
    	fast = slow = head;
    	while(fast != rear && fast->next != rear)
    	{
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	right = slow->next;
    	slow->next = NULL;
    	left = divide(head, slow);
    	right = divide(right, rear);
    	return conquer(left, right);
    }
    ListNode *conquer(ListNode *left, ListNode *right)
    {
    	if (left == NULL)
    		return right;
    	else if (right == NULL)
    		return left;
    	if (left->val < right->val)
    	{
    		left->next = conquer(left->next, right);
    		return left;
    	}
    	else
    	{
    		right->next = conquer(left, right->next);
    		return right;
    	}
    }
};

//--- method 2: quick sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	return divide(head);
    }
    ListNode *divide(ListNode *head)
    {
    	if (!head)  return NULL;
    	else if (!head->next) return head;

    	ListNode *small_head = new ListNode(0), *small_rear = small_head;
    	ListNode *equal_head = new ListNode(0), *equal_rear = equal_head;
    	ListNode *large_head = new ListNode(0), *large_rear = large_head;
    	ListNode *merge_head = new ListNode(0), *merge_rear = merge_head;
    	ListNode *cur = head;

    	while(cur)
    	{
    		if (cur->val == head->val)
    		{
    			equal_rear->next = cur;
    			equal_rear = cur;
    		}
    		else if (cur->val > head->val)
    		{
    			large_rear->next = cur;
    			large_rear = cur;
    		}
    		else if (cur->val < head->val)
    		{
    			small_rear->next = cur;
    			small_rear = cur;
    		}
    		cur = cur->next;
    	}
    	equal_rear->next = NULL;
    	large_rear->next = NULL;
    	small_rear->next = NULL;

    	cur = divide(small_head->next);
    	if (cur)
    	{
    		merge_rear->next = cur;
    	 	merge_rear = cur;
    		while(cur->next)
	    		cur = cur->next;
	    	cur->next = equal_head->next;
    	}
    	else
    	{
    		merge_rear->next = equal_head->next;
    	 	merge_rear = equal_head->next;
    	}
    	equal_rear->next = divide(large_head->next);
    	return merge_head->next;
    }
};