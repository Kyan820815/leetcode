//--- Q: 384. Shuffle an Array

//--- method 1: resivoir sampling
class Solution {
public:
    Solution(vector<int>& nums) {
        cpy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
    	return cpy;  
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    	vector<int> res = cpy;
        for (int i = 0; i < res.size(); ++i)
        	swap(res[rand()%(i+1)], res[i]);
        return res;
    }
private:
	vector<int> cpy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */