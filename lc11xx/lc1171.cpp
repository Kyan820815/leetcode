//--- Q: 1171. Remove Zero Sum Consecutive Nodes from Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: prefix sum
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *cur = head, *dummy = new ListNode(-1);
        dummy->next = head;
        unordered_map<int, ListNode*> prefix_sum;
        prefix_sum[0] = dummy;
        int sum = 0;
        while (cur)
        {
        	sum += cur->val;
        	if (prefix_sum.find(sum) == prefix_sum.end())
        		prefix_sum[sum] = cur;
        	else
            {
                ListNode *tmp = prefix_sum[sum]->next;
                int tmp_sum = sum;
                while (tmp != cur)
                {
                    tmp_sum += tmp->val;
                    prefix_sum.erase(tmp_sum);
                    tmp = tmp->next;
                }
                prefix_sum[sum]->next = cur->next;
            }
        	cur = cur->next;
        }
        return dummy->next;
    }
};