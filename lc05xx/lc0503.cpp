//--- Q: 0503. Next Greater Element II
    
//--- method 1: O(n) two pass
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1), sk;
        for (int i = 0; i < nums.size(); ++i) {
            while (sk.size() && nums[sk.back()] < nums[i]) {
                res[sk.back()] = nums[i];
                sk.pop_back();
            }
            sk.push_back(i);
        }
        for (int i = 0; i < nums.size(); ++i) {
            while (sk.size() && nums[sk.back()] < nums[i]) {
                res[sk.back()] = nums[i];
                sk.pop_back();
            }
        }
        return res;
    }
};