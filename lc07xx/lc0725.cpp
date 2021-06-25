//--- Q: 725. Split Linked List in Parts

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: link list operation
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
    	ListNode *cur = root;
    	vector<ListNode *> res(k);
    	int cnt = 0, rem, quo;
    	while (cur)
    	{
    		cur = cur->next;
    		++cnt;
    	}
    	cur = root;
		quo = cnt / k;
		rem = cnt % k;
		for (int i = 0; i < k && cur; ++i)
		{
			ListNode *last = cur;
			res[i] = cur;
			cur = cur->next;
			for (int j = 1; j < quo + (i < rem); ++j)
			{
				last = cur;
				cur = cur->next;
			}
			last->next = NULL;
		}
    	return res;
    }
};