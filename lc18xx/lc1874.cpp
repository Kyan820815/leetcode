//--- Q: 1874. Minimize Product Sum of Two Arrays

//--- method 1: bucket sort
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n1(101, 0), n2(101, 0);
        for (int i = 0; i < nums1.size(); ++i) {
            ++n1[nums1[i]];
            ++n2[nums2[i]];
        }
        int i = 1, j = 100, res = 0;
        while (i <= 100 && j >= 1) {
            while (i <= 100 && !n1[i]) {
                ++i;
            }
            while (j >= 1 && !n2[j]) {
                --j;
            }
            if (i > 100 || j < 1) {
                break;
            }
            res += i*j;
            --n1[i];
            --n2[j];
        }
        return res;
    }
};

//--- method 2: sort
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0, j = nums1.size()-1; i < nums1.size(); ++i,--j) {
            res += nums1[i]*nums2[j];
        }
        return res;
    }
};