//--- Q: 1838. Frequency of the Most Frequent Element

//--- method 1: sliding window
class Solution {
public:
    using ll = long long;
    int maxFrequency(vector<int>& nums, int k) {
        int left = 0, right = 1, n = nums.size(), res = 1;
        ll curk = 0;
        sort(nums.begin(), nums.end());
        while (right < n) {
            if (nums[right] != nums[right-1]) {
                curk += (ll)(nums[right]-nums[right-1])*(right-left);
            }
            while (curk > k) {
                curk -= (nums[right]-nums[left++]);
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};
