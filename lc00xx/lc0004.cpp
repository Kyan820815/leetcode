//--- Q: 0004. Median of Two Sorted Arrays
//--- last written: 2023/07/01

//--- method 1: binary search for two arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = (nums1.size()+nums2.size()+1)/2;
        int n2 = (nums1.size()+nums2.size()+2)/2;
        return (double)(findk(0, 0, n1, nums1, nums2)
											+ findk(0, 0, n2, nums1, nums2))/2;
    }
    int findk(int i, int j, int k, vector<int> &nums1, vector<int> &nums2) {
        if (i == nums1.size()) {
            return nums2[j+k-1];
        } else if (j == nums2.size()) {
            return nums1[i+k-1];
        }
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }
        int lv = i+k/2-1 >= nums1.size() ? INT_MAX : nums1[i+k/2-1];
        int rv = j+k/2-1 >= nums2.size() ? INT_MAX : nums2[j+k/2-1];
        return lv < rv ? findk(i+k/2, j, k-k/2, nums1, nums2)
											 : findk(i, j+k/2, k-k/2, nums1, nums2);
    }
};
