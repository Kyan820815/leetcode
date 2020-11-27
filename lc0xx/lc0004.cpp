//--- Q: 4. Median of Two Sorted Arrays

//--- method 1: binary search for two arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int n1 = nums1.size(), n2 = nums2.size();
    	int left = (n1+n2+1)/2, right = (n1+n2+2)/2;
    	return double(findkth(nums1, 0, nums2, 0, left) + findkth(nums1, 0, nums2, 0, right))/2.0;
    }
    int findkth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
    	if (i >= nums1.size())
    		return nums2[j+k-1];
    	if (j >= nums2.size())
    		return nums1[i+k-1];
    	if (k == 1)
    		return min(nums1[i], nums2[j]);
    	int midval1 = (i+k/2-1 < nums1.size()) ? nums1[i+k/2-1] : INT_MAX;
    	int midval2 = (j+k/2-1 < nums2.size()) ? nums2[j+k/2-1] : INT_MAX;
    	if (midval1 < midval2)
    		return findkth(nums1, i+k/2, nums2, j, k-k/2);
    	else
    		return findkth(nums1, i, nums2, j+k/2, k-k/2);
    }
};