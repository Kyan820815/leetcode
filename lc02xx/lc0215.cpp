//--- Q: 0215. Kth Largest Element in an Array

//--- method 1: O(n), quick select
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        --k;
        while (left < right) {
            int mid = partition(left, right, nums);
            if (mid < k) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
    int partition(int start, int end, vector<int> &nums) {
        int pivot = random()%(end-start+1) + start;
        int idx = start-1;
        swap(nums[end], nums[pivot]);
        for (int i = start; i <= end; ++i) {
            if (nums[i] > nums[end]) {
                swap(nums[++idx], nums[i]);
            }
        }
        swap(nums[++idx], nums[end]);
        return idx;
    }
};

//--- method 2: min heap, o(nlogk)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for (auto &num: nums) {
            que.push(num);
            if (que.size() > k) {
                que.pop();
            }
        }
        return que.top();
    }
};