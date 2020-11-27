//--- Q: 398. Random Pick Index

//--- method 1: resivoir sampling
class Solution {
public:
	vector<int> idx;
    Solution(vector<int>& nums) {
    	idx = nums;
    }
    
    int pick(int target) {
    	int cnt = 0, res;
    	for (int i = 0; i < idx.size(); ++i)
    	{
    		if (target != idx[i]) continue;
    		cnt++;
    		if (rand()%cnt == 0)
    			res = i;
    	}
    	return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */