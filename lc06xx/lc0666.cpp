//--- Q: 0666. Path Sum IV

//--- method 1: array representation, 1 pass
class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> sum(5, vector<int>(8,0));
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int lv = nums[i]/100, idx = (nums[i]%100)/10-1, val = nums[i]%10;
            sum[lv][idx] += val;
            if (sum[lv-1][idx/2] > 0) {
                res -= sum[lv-1][idx/2];
                sum[lv-1][idx/2] *= -1;
            }
            sum[lv][idx] += abs(sum[lv-1][idx/2]);
            res += sum[lv][idx];
        }
        return res;
    }
};