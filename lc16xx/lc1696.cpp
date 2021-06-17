//--- Q: 1696. Jump Game VI

//--- method 1: decreasing dequeue
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>> que;
        int now;
        for (int i = 0; i < nums.size(); ++i) {
            now = nums[i]+(que.size() ? que.front().second : 0);
            while (que.size() && que.back().second < now) {
                que.pop_back();
            }
            que.push_back({i,now});
            if (i-que.front().first >= k) {
                que.pop_front();
            }
        }
        return now;
    }
};  