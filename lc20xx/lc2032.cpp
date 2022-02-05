//--- Q: 2032. Two Out of Three

//--- method 1: count unique frequencies
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res, cnt1(101, 0), cnt2(101, 0), cnt3(101, 0);
        for (auto &num: nums1) {
            cnt1[num] = 1;
        }
        for (auto &num: nums2) {
            cnt2[num] = 1;
        }
        for (auto &num: nums3) {
            cnt3[num] = 1;
        }
        for (int i = 1; i <= 100; ++i) {
            if (cnt1[i]+cnt2[i]+cnt3[i] > 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};