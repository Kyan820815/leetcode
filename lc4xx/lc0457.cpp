//--- Q: 457. Circular Array Loop

//--- method 1: slow & fast pointer
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            int slow = i, fast = i;
            while (1) {
                slow = nextIndex(slow, n, nums[slow]);
                fast = nextIndex(fast, n, nums[fast]);
                fast = nextIndex(fast, n, nums[fast]);
                if (slow == fast) {
                    break;
                }
            }
            if (!nums[slow]) {
                break;
            }
            // find start point of cycle
            slow = i;
            while (slow != fast) {
                int jump = nums[slow];
                nums[slow] = 0;
                slow = nextIndex(slow, n, jump);
                fast = nextIndex(fast, n, nums[fast]);
            }
            int begin = fast, step = 0, valid = 1, dir = -1;
            // check if cyles step > 1 and correct direction
            while (dir == -1 || fast != begin) {
                if (dir != -1 && dir > 0 != nums[fast] > 0) {
                    valid = 0;
                }
                dir = nums[fast] > 0;
                int jump = nums[fast];
                nums[fast] = 0;
                fast = nextIndex(fast, n, jump);
                ++step;
            }
            if (step > 1 && valid) {
                return true;
            }
        }
        return false;
    }
    int nextIndex(int idx, int n, int jump) {
        return (((idx+jump)%n)+n)%n;
    }
};