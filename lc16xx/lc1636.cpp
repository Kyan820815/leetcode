//-- Q: 1636. Sort Array by Increasing Frequency

//--- method 1: bucket sort
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> cnt(201, 0);
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]+100];
        }
        sort(nums.begin(), nums.end(), [&cnt](int &a, int &b) {
            return cnt[a+100] < cnt[b+100] || cnt[a+100] == cnt[b+100] && a > b;
        });
        return nums;
    }
};