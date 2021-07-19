//--- Q: 0384. Shuffle an Array

//--- method 1: resivoir sampling
class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> rtn = arr;
        for (int i = 0; i < rtn.size(); ++i) {
            swap(rtn[random()%(i+1)], rtn[i]);
        }
        return rtn;
    }
    vector<int> arr;
};

//--- method 2: swap with last element
class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> rtn = arr;
        for (int i = rtn.size(); i >= 1;) {
            auto idx = random()%i;
            swap(rtn[idx], rtn[--i]);
        }
        return rtn;
    }
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */