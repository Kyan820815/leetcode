//--- Q: 1885. Count Pairs in Two Arrays

//--- method 1: greedy two pointers
class Solution {
public:
    using ll = long long;
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        ll res = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            nums1[i] -= nums2[i];
        }
        sort(nums1.begin(), nums1.end());
        int left = 0, right = nums1.size()-1;
        while (left < right) {
            if (nums1[left]+nums1[right] > 0) {
                res += right-left;
                --right;
            } else {
                ++left;
            }
        }
        return res;
    }
};