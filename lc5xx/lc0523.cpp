//--- Q: 523. Continuous Subarray Sum

//--- method 1: dp iteration with memorizing first remainder index
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map{{0,-1}};
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	sum += nums[i];
            int rem = (!k) ? sum : sum%k;
        	if (map.count(rem))
            {
                if (i-map[rem] > 1) return true;
            }
            else map[rem] = i;
        }
        return false;
    }
};