//--- Q: 1046. Last Stone Weight

//--- method 1: nlogn sort
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1)
        {
        	sort(stones.begin(), stones.end());
        	int a = stones[stones.size()-1], b = stones[stones.size()-2];
        	stones.pop_back();
        	stones.pop_back();
        	if (a!=b)
        		stones.push_back(a-b);
        }
        return (!stones.size()) ? 0 : stones[0];
    }
};

//--- method 2: priority queue, better
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    	priority_queue<int> que;
    	for (int i = 0; i < stones.size(); ++i)
    		que.push(stones[i]);
    	while (que.size() > 1)
    	{
    		int a = que.top();
    		que.pop();
    		int b = que.top();
    		que.pop();
    		if (a!=b)
    			que.push(a-b);
    	}
        return (!que.size()) ? 0 : que.top();
    }
};