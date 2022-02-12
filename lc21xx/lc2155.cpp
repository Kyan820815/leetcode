//--- Q: 2155. All Divisions With the Highest Score of a Binary Array

//--- method 1: two pointers
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size(), leftzero = 0, rightone = 0;
        for (auto &num: nums) {
            rightone += num;
        }
        vector<int> res = {0};
        int rescnt = rightone;
        for (int i = 0; i < n; ++i) {
            leftzero += !nums[i];
            rightone -= nums[i];
            int curcnt = leftzero+rightone;
            if (curcnt > rescnt) {
                rescnt = curcnt;
                res = {i+1};
            } else if (curcnt == rescnt) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};