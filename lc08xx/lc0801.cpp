//--- Q: 0801. Minimum Swaps To Make Sequences Increasing

//--- mehtod 1: dp iteration, O(n) space
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> swap(n, INT_MAX), noswap(n, INT_MAX);
        swap[0] = 1, noswap[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) {
                noswap[i] = noswap[i-1];
                swap[i] = swap[i-1]+1;
            }
            if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
                noswap[i] = min(noswap[i], swap[i-1]);
                swap[i] = min(swap[i], noswap[i-1]+1);
            }
        }
        return min(swap.back(), noswap.back());
    }
};

//--- method 2: dp iteration, O(1) space
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int swap = 1, noswap = 0;
        for (int i = 1; i < n; ++i) {
            int lastswap = swap, lastnoswap = noswap;
            swap = n, noswap = n;
            if (nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) {
                noswap = lastnoswap;
                swap = lastswap+1;
            }
            if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
                noswap = min(noswap, lastswap);
                swap = min(swap, lastnoswap+1);
            }
        }
        return min(swap, noswap);
    }
};