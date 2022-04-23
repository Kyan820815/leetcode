//--- Q: 1980. Find Unique Binary String

//--- method 1: grab diffrent value for given index of each num
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res;
        for (int i = 0; i < n; ++i) {
            res.push_back(nums[i][i] == '0' ? '1' : '0');
        }
        return res;
    }
};