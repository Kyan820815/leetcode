//--- Q: 147. Insertion Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: O(1) space insertion sort
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *prev, *cur, *tmp, *insertion;
        if (!head) return NULL;
        prev = head, cur = head->next;
        dummy->next = head;

        while(cur)
        {
            insertion = dummy;
            tmp = cur;
            cur = cur->next;            
            while(insertion->next != tmp && insertion->next->val < tmp->val)
                insertion = insertion->next;
            if (insertion->next != tmp)
            {
                tmp->next = insertion->next;
                insertion->next = tmp;
                prev->next = cur;
            }
            else
                prev = tmp;
        }
        return dummy->next;
    }
};

//--- method 2: normal inserton sort, O(n) space
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> sort;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *now = dummy;
        while(now)
        {
        	sort.push_back(now);
        	now = now->next;
        }
        for (int i = 2; i < sort.size(); ++i)
        {
        	int j, happen = 0;
        	ListNode *ch = sort[i];
        	for (j = i-1; j >= 1; --j)
        	{
        		if (sort[j]->val > ch->val)
        		{
        			if (!happen)
        			{
	        			sort[j]->next = sort[j+1]->next;
	        			happen = 1;
        			}
        			sort[j+1] = sort[j];
        		}
        		else break;
        	}
        	if (happen)
        	{
	        	ch->next = sort[j]->next;
	   	     	sort[j]->next = ch;
        	}
        	sort[j+1] = ch;
        }
        return dummy->next;
    }
};