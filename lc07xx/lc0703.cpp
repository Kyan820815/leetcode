//--- Q: 703. Kth Largest Element in a Stream

//--- method 1: 
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (que.size() < k)
    			que.push(nums[i]);
    		else if (que.top() < nums[i])
    		{
				que.pop();
				que.push(nums[i]);
    		}
    	}
    }
    
    int add(int val) {
        if (que.size() && que.top() < val)
		{
			que.pop();
			que.push(val);
		}
		return que.top();
    }
  	priority_queue<int, vector<int>, greater<int>> que;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */