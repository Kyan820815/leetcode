//--- Q: 0985. Sum of Even Numbers After Queries

//--- method 1: track even sum
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int even = 0;
        for (auto &num: nums) {
            if (!(num&1)) {
                even += num;
            }
        }
        for (auto &query: queries) {
            if (!(nums[query[1]]&1)) {
                even -= nums[query[1]];
            }
            nums[query[1]] += query[0];
            if (!(nums[query[1]]&1)) {
                even += nums[query[1]];
            }
            res.push_back(even);
        }
        return res;
    }
};