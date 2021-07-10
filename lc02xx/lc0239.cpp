//--- Q: 0239. Sliding Window Maximum

//--- method 1: deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while (que.size() && nums[que.back()] < nums[i]) {
                que.pop_back();
            }
            que.push_back(i);
            if (i-que.front() >= k) {
                que.pop_front();
            }
            if (i >= k-1) {
                res.push_back(nums[que.front()]);
            }
        }
        return res;
    }
};
