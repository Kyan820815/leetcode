//--- Q: 1437. Check If All 1's Are at Least Length K Places Away

//--- method 1: linear search
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -(++k);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                if (i-last < k) {
                    return false;
                }
                last = i;
            }
        }
        return true;
    }
};