//--- Q: 1673. Find the Most Competitive Subsequence

//--- method 1: stack
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> sk;
        for (int i = 0; i < nums.size(); ++i) {
            while (sk.size() && nums[i] < sk.back() && k-sk.size() <= nums.size()-i-1) {
                sk.pop_back();
            }
            if (sk.size() < k) {
                sk.push_back(nums[i]);
            }
        }
        return sk;
    }
};