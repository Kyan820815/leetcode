//--- Q: 1855. Maximum Distance Between a Pair of Values

//--- method 1: binary search
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int left = i, right = m-1;
            while (left <= right) {
                int mid = left + (right-left)/2;
                if (nums2[mid] >= nums1[i]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            res = max(res, right-i);
        }
        return res;
    }
};

//--- method 2: two pointer
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int res = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < m && nums1[i] <= nums2[j]) {
                ++j;
            }
            res = max(res, j-i-1);
        }
        return res;
    }
};