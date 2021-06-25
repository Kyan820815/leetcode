//--- Q: 239. Sliding Window Maximum

//--- method 1: priority_queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	vector<int> res;
    	priority_queue<pair<int,int>> que;
    	int maxv = INT_MIN;
    	for (int i = 0; i < nums.size(); ++i)
    	{
            while (que.size() && que.top().second <= i-k)
                que.pop();
            que.push({nums[i], i});
            if (i >= k-1) 
                res.push_back(que.top().first);
    	}
    	return res;
    }
};

//--- method 2: queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	deque<int> que;
    	vector<int> res;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (que.size() && que.front() <= i-k) que.pop_front();
    		while (que.size() && nums[que.back()] < nums[i])
    			que.pop_back();
    		que.push_back(i);
    		if (i >= k-1)
    			res.push_back(nums[que.front()]);
    	}
    	return res;
    }
};
