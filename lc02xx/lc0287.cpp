//--- Q: 0287. Find the Duplicate Number

//--- method 1: slow & fast pointer
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
//--- method 2: binary search, time: nlogn, space: 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size();
        while (left < right) {
            int mid = left + (right-left)/2, cnt = 0;
            for (auto &num: nums) {
                cnt += num <= mid;
            }
            if (cnt > mid) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};