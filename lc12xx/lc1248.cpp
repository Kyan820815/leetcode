//--- Q: 1248. Count Number of Nice Subarrays

//--- method 1: O(1) space two pass
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums, k) - atmostk(nums, k-1);
    }
    int atmostk(vector<int> &nums, int k) {
        int left = 0, right = 0, res = 0;
        while (right < nums.size()) {
            k -= nums[right]&1;
            while (k < 0) {
                k += nums[left++]&1;
            }
            res += right-left+1;
            ++right;
        }
        return res;
    }
};

//--- method 2: O(1) space one pass

//--- method 2: O(k) space queue, one pass
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0, res = 0;
        queue<int> que;
        while (right < n) {
            if (nums[right]&1) {
                que.push(right);
            }
            if (que.size() > k) {
                left = que.front()+1;
                que.pop();
            }
            if (que.size() == k) {
                res += (que.front()-left+1);
            }
            ++right;
        }
        return res;
    }
};
