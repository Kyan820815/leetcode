//--- Q: 1567. Maximum Length of Subarray With Positive Product

//--- method 1: one pass count first neg index
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pivot = -1, neg = 0, res = 0, fnegi;
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i]) {
                pivot = i;
                neg = 0;
                continue;
            } else if (nums[i] < 0) {
                if (++neg == 1) {
                    fnegi = i;
                }
            }
            if (!(neg&1)) {
                res = max(res, i-pivot);
            } else {
                res = max(res, i-fnegi);
            }
        }
        return res;
    }
};