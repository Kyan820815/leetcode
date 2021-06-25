//--- Q: 457. Circular Array Loop

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
                slow = next(slow, nums);
                fast = next(fast, nums);
                fast = next(fast, nums);
                if (slow == fast) {
                    break;
                }
            }
            // since there is only one loop in array
            if (!nums[slow]) {
                break;
            }
            int pos = slow, step = 0, ps = 0, ng = 0;
            while (1) {
                int next_pos = next(pos, nums);
                if (nums[pos] > 0) {
                    ++ps;
                } else {
                    ++ng;
                }
                nums[pos] = 0;
                ++step;
                pos = next_pos;
                if (pos == slow) {
                    if (step > 1 && (ps == 0 || ng == 0)) {
                        return true;
                    }
                    break;
                }
            }
        }
        return false;
    }
    int next(int i, vector<int> &nums) {
        int pos = (i+nums[i]+nums.size())%nums.size();
        return pos;
    }
};
