//--- Q: 0457. Circular Array Loop

//--- method 1: slow & fast pointer
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i]) {
                continue;
            }
            int slow = i, fast = i;
            while (1) {
                slow = findnext(slow, nums);
                fast = findnext(fast, nums);
                fast = findnext(fast, nums);
                if (slow == fast) {
                    break;
                }
            }
            if (!nums[slow]) {
                break;
            }
            int start = slow, now = start, cnt = 0,  dir = 0;
            while (1) {
                dir += (nums[now] > 0) ? 1 : -1;
                auto next = findnext(now, nums);
                nums[now] = 0;
                now = next;
                ++cnt;
                if (now == start) {
                    if (abs(dir) == cnt && cnt > 1) {
                        return true;
                    } else {
                        break;
                    }
                }
            }
        }
        return false;
    }
    int findnext(int idx, vector<int> &nums) {
        int n = nums.size();
        return ((idx+nums[idx])%n+n)%n;
    }
};