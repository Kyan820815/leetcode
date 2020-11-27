//--- Q: 1313. Decompress Run-Length Encoded List

//--- method 1: O(n*m)
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = 0; j < nums[i]; ++j) {
                res.push_back(nums[i+1]);
            }
        }
        return res;
    }
};