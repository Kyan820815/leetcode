//--- Q: 23. Merge k Sorted Lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if (!lists.size()) return NULL;
        return divide(lists, 0, lists.size()-1);
    }
    ListNode *divide(vector<ListNode*> &lists, int left, int right)
    {
    	ListNode *left_list, *right_list, *general_list;
    	if (left < right)
    	{
    		int mid = (left+right) / 2;
    		left_list = divide(lists, left, mid);
    		right_list = divide(lists, mid+1, right);
    		general_list = conquer(left_list, right_list);
    	} else return lists[left];
    	return general_list;
    }
    ListNode *conquer(ListNode *l1, ListNode *l2)
    {
    	if (!l1) return l2;
    	if (!l2) return l1;
    	if (l1->val < l2->val)
    	{
    		l1->next = conquer(l1->next, l2);
    		return l1;
    	}
    	else
    	{
    		l2->next = conquer(l1, l2->next);
    		return l2;
    	}
    	return NULL;
    }
};

//--- method 2: priority_queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode *cur, *dummy = new ListNode(-1);
    	cur = dummy;
    	auto comp = [](ListNode *a, ListNode *b)
    	{
    		return a->val > b->val;
    	};
    	priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> que(comp);
    	for (int i = 0; i < lists.size(); ++i)
            if (lists[i]) que.push(lists[i]);
    	while (que.size())
    	{
    		ListNode *tmp = que.top();
    		que.pop();
            if (tmp->next)
                que.push(tmp->next);
    		cur->next = tmp;
    		cur = tmp;
    	}
    	return dummy->next;
    }
};
