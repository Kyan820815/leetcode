//--- Q: 075. Sort Colors

//--- method 1-1: my version of swap, better
class Solution {
public:
    void sortColors(vector<int>& nums) {
		int len = nums.size(), one_end = -1, two_begin = len;

		for (int i = 0; i < len;)
		{
			if (nums[i] == 0)
			{
				swap(nums[i], nums[++one_end]);
				i++;
			}
			else if (nums[i] == 2)
			{
				if (i >= two_begin) 
				{
					i++;
					continue;
				}
				swap(nums[i], nums[--two_begin]);
				
			}
			else i++;
		}
    }
};

//--- method 1-2: swap, faster than vector erase
class Solution {
public:
    void sortColors(vector<int>& nums) {
		int len = nums.size(), one_end = -1, two_begin = len;

		for (int i = 0; i < len; ++i)
		{
			while(nums[i] != 1)
			{
				if (nums[i] == 0)
				{
					if (i <= one_end) break;
					swap(nums[i], nums[++one_end]);
				}
				if (nums[i] == 2)
				{
					if (i >= two_begin) break;
					swap(nums[i], nums[--two_begin]);
				}
			}
		}
    }
};

//--- method 2: vector insert & erase
class Solution {
public:
    void sortColors(vector<int>& nums) {
		int len = nums.size(), count = 0;
		for (int i = 0; i < len && count < len;)
		{
			if (nums[i] == 0)
			{
				nums.insert(nums.begin(),nums[i]);
				nums.erase(nums.begin()+i+1);
				i++;
			}
			else if (nums[i] == 2)
			{
				nums.insert(nums.end(),nums[i]);
				nums.erase(nums.begin()+i);
			}
			else i++;
			count++;
		}
    }
};