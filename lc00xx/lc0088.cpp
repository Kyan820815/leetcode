//--- Q: 88. Merge Sorted Array

//--- method 1: backward insert, better
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1, i = m-1, j = n-1;
        while (i>=0 && j>= 0)
        {
        	if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        	else nums1[k--] = nums2[j--];
        }
        while (i >= 0)
        	nums1[k--] = nums1[i--];
        while (j >= 0)
        	nums1[k--] = nums2[j--];
    }
};

//--- method 2: insertion sort 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; ++i)
        {
            int j;
        	for (j = 0; j < m+i; ++j)
        	{
        		if (nums2[i] < nums1[j])
        		{
        			for (int k = m+i-1; k >= j; --k)
        				nums1[k+1] = nums1[k];
        			nums1[j] = nums2[i];
                    break;
        		}
            }
            if (j >= m+i)
                nums1[j] = nums2[i];
                
        }
    }
};