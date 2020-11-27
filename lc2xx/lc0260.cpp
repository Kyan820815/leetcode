//--- Q: 260. Single Number III

//--- method 1:  find the first different bit from left to right
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        vector<int> out(2,0);
        for (int i = 0; i < nums.size(); ++i)
        	diff ^= nums[i];
        diff = diff & (~diff+1);
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] & diff)
        		out[0] ^= nums[i];
        	else
        		out[1] ^= nums[i];
        }
        return out;
    }
};