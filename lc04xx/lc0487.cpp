//--- Q: 0487. Max Consecutive Ones II

//--- method 1: two pointer
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left, right, res = 0, k = 1;
        for (left = 0, right = 0; right < nums.size(); ++right) {
            k -= !nums[right];
            for (; k < 0; ++left) {
                k += !nums[left];
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};

//--- method 2: follow up
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left, right, res = INT_MIN, k = 1;
        deque<int> que;
        for (left = 0, right = 0; right < nums.size(); ++right) {
            if (!nums[right]) {
                que.push_back(right);
                --k;
            }
            if (k < 0) {
                left = que.front()+1;
                que.pop_front();
                ++k;
            }
            res = max(res, right-left+1);
        }
        return res == INT_MIN ? nums.size() : res;
    }
};