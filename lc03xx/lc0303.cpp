//--- Q: 0303. Range Sum Query - Immutable

//--- method 1: dp, sum of array til index i
class NumArray {
public:
    NumArray(vector<int>& nums) {
        for (auto &num: nums) {
            sum.push_back(sum.back()+num);
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right+1]-sum[left];
    }
    
    vector<int> sum = {0};
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */