//--- Q: 189. Rotate Array

//--- method 1: triple reverse 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0 || !nums.size()) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

//--- method 2: shift, record last nums[i]
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0 || !n) return;
        int cur = 0, idx = 0, pre = nums[0], start = 0;
        for (int i = 0; i < n; ++i)
        {
        	cur = nums[(idx+k)%n];
        	nums[(idx+k)%n] = pre;
        	pre = cur;
        	idx = (idx+k)%n;
            if (idx == start)
            {
                idx = ++start;
                pre = nums[idx];
            }
        }
    }
};

//--- method 3: erase & push_back, slow
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0 || !nums.size()) return;
        for (int i = 0; i < nums.size()-k; ++i)
        {
        	nums.push_back(nums[0]);
        	nums.erase(nums.begin());
        }
    }
};