//--- Q: 0229. Majority Element II

//--- method 1: O(n) one pass
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, v1 = INT_MIN, v2 = INT_MIN;
        for (auto &num: nums) {
            if (v1 == num) {
                ++cnt1;
            } else if (v2 == num) {
                ++cnt2;
            } else if (!cnt1) {
                ++cnt1;
                v1 = num;
            } else if (!cnt2) {
                ++cnt2;
                v2 = num;
            } else {
                if (!--cnt1) {
                    v1 = INT_MIN;
                }
                if (!--cnt2) {
                    v2 = INT_MIN;
                }
            }
        }
        cnt1 = cnt2 = 0;
        for (auto &num: nums) {
            if (v1 == num) {
                ++cnt1;
            } else if (v2 == num) {
                ++cnt2;
            }
        }
        vector<int> res;
        if (cnt1 > nums.size()/3) {
            res.push_back(v1);
        }
        if (cnt2 > nums.size()/3) {
            res.push_back(v2);
        }
        return res;
    }
};