//--- Q: 445. Add Two Numbers II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: stack operation 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<ListNode *> sl1, sl2;
		ListNode *now, *l3 = NULL;
		int rem = 0, carry = 0;
		now = l1;
		while (now)
		{
			sl1.push(now);
			now = now->next;
		}
		now = l2;
		while (now)
		{
			sl2.push(now);
			now = now->next;
		}

		while (sl1.size() || sl2.size() || carry)
		{
			int v1 = 0, v2 = 0;
			if (sl1.size())
			{
				v1 = sl1.top()->val;
				sl1.pop();
			}
			if (sl2.size())
			{
				v2 = sl2.top()->val;
				sl2.pop();
			}
			rem = (v1 + v2 + carry) % 10;
			carry = (v1 + v2 + carry) / 10;
			now = new ListNode(rem);
			now->next = l3;
			l3 = now;
		}
        return l3;
    }
};

//--- method 2: recursion
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int n1 = lenth(l1);
    	int n2 = lenth(l2);
    	ListNode *head =  (n1 > n2) ? dfs(l1, l2, n1-n2) : dfs(l2, l1, n2-n1);
    	if (head->val > 9)
    	{
    		head->val %= 10;
    		ListNode *newHead = new ListNode(1);
    		newHead->next = head;
    		return newHead;
    	}
    	return head;
    }
    int lenth(ListNode *list)
    {
    	int n = 0;
    	while (list)
    	{
    		list = list->next;
    		++n;
    	}
    	return n;
    }
    ListNode *dfs(ListNode *l1, ListNode *l2, int diff)
    {
    	if (!l1) return NULL;
    	ListNode *res = (diff) ? new ListNode(l1->val) : new ListNode(l1->val+l2->val);
    	ListNode *pos = (diff) ? dfs(l1->next, l2, diff-1) : dfs(l1->next, l2->next, 0);
    	if (pos && pos->val > 9)
    	{
    		pos->val %= 10;
    		++res->val;
    	}
    	res->next = pos;
    	return res;
    }
};

//--- method 3: reverse link list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ll1 = NULL, *ll2 = NULL, *ll3 = NULL;
        ListNode *now;
        int carry = 0;
        now = l1;
        while (now)
        {
        	ListNode *tmp = now;
        	now = now->next;
        	tmp->next = ll1;
        	ll1 = tmp;
        }
        now = l2;
        while (now)
        {
        	ListNode *tmp = now;
        	now = now->next;
        	tmp->next = ll2;
        	ll2 = tmp;
        }
        while (ll1 || ll2 || carry)
        {
        	int l1_v = (ll1) ? ll1->val : 0;
        	int l2_v = (ll2) ? ll2->val : 0;
        	int rem = (l1_v + l2_v + carry) % 10;
        	carry = (l1_v + l2_v + carry) / 10;
        	now = new ListNode(rem);
        	now->next = ll3;
        	ll3 = now;
        	if (ll1)
        		ll1 = ll1->next;
        	if (ll2)
        		ll2 = ll2->next;
        }
        return ll3;
    }
};