//--- Q: 0462. Minimum Moves to Equal Array Elements II

//--- method 1: quick select
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = nums.size()/2, res = 0;
        nth_element(nums.begin(), nums.begin()+mid, nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[mid]) {
                res += abs(nums[mid]-nums[i]);
            }
        }
        return res;
    }
};

//--- method 2: sort
class Solution {
public:
    using ll = long long;
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<ll> left(nums.size());
        for (int i = 1; i < nums.size(); ++i) {
            left[i] = left[i-1] + (nums[i]-nums[i-1]) * i;
        }
        ll right = 0, res = INT_MAX;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (i < nums.size()-1) {
                right += (nums.size()-i-1) * (nums[i+1]-nums[i]);
            }
            res = min(res, left[i]+right);
        }
        return res;
    }
};