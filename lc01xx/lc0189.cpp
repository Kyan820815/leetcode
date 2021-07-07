//--- Q: 0189. Rotate Array

//--- method 2: shift, record last nums[i], my version
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), cnt = nums.size(), start = 0;
        while (cnt) {
            int next = (start+k) % n, pre = nums[start];
            while (next != start) {
                auto tmp = nums[next];
                nums[next] = pre;
                pre = tmp;
                next = (next+k) % n;
                --cnt;
            }
            nums[start++] = pre;
            --cnt;
        }
    }
};

//--- method 2: triple reverse 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
