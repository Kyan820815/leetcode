//--- Q: 1425. Constrained Subsequence Sum

//--- method 1: deque
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> que;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (que.size() && i-que.front() > k) {
                que.pop_front();
            }
            if (que.size()) {
                nums[i] += max(0, nums[que.front()]);
            }
            while (que.size() && nums[que.back()] < nums[i]) {
                que.pop_back();
            }
            que.push_back(i);
            res = max(res, nums[i]);
        }
        return res;
    }
};

//--- method 2: priority queue
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        auto comp = [&nums](int &a, int &b) {
            return nums[a] < nums[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> que(comp);
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int val = 0;
            while (que.size()) {
                auto now = que.top();
                if (i-now > k) {
                    que.pop();
                    continue;
                }
                val = max(val, nums[now]);
                break;
            }
            nums[i] += val;
            que.push(i);
            res = max(res, nums[i]);
        }
        return res;
    }
};