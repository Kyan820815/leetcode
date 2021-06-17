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

//--- method 2-1: shift, record last nums[i]
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), pre = nums[0], idx = 0, start = 0;
        k %= n;
        for (int i = 0; i < n; ++i) {
            int cur = nums[(idx+k)%n];
            nums[(idx+k)%n] = pre;
            pre = cur;
            idx = (idx+k)%n;
            if (idx == start) {
                idx = (++start)%n;
                pre = nums[idx];
            }
        }
    }
};

//--- method 2-2: shift, record last nums[i], my version
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), cnt = n, start = 0;
        while (cnt) {
            int next = (start+k)%n, last = nums[start];
            while (next != start) {
                int tmp = nums[next];
                nums[next] = last;
                next = (next+k)%n;
                last = tmp;
                --cnt;
            }
            nums[start++] = last;
            --cnt;
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