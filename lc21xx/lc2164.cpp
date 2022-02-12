//--- Q: 2164. Sort Even and Odd Indices Independently

//--- method 1: split, sort then merge
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for (int i = 0; i < nums.size(); ++i) {
            if (i&1) {
                odd.push_back(nums[i]);
            } else {
                even.push_back(nums[i]);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.rbegin(), odd.rend());
        vector<int> res;
        int i = 0;
        while (i < even.size()) {
            res.push_back(even[i]);
            if (i < odd.size()) {
                res.push_back(odd[i]);
            }
            i++;
        }
        return res;
    }
};