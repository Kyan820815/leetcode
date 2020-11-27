//--- Q: 162. Find Peak Element

//--- method 1: O(logN) time, binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right)
        {
        	int mid = (left+right) / 2;
        	if (nums[mid] < nums[mid+1])
        		left = mid+1;
        	else
        		right = mid;
        }
        return nums[right];
    }
};

//--- method 2: O(N) time
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
        	if ((i == 0 || nums[i] > nums[i-1]) && (i == nums.size()-1 || nums[i] > nums[i+1]))
        		return i;
        }
        return -1;
    }
};