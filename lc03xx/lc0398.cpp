//--- Q: 0398. Random Pick Index

//--- method 1: resivoir sampling
class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;        
    }
    
    int pick(int target) {
        int cnt = 0, res;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) {
                if (random()%(cnt+1) == cnt) {
                    res = i;                    
                }
                ++cnt;
            }
        }
        return res;
    }
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */