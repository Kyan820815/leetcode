//--- Q: 1353. Maximum Number of Events That Can Be Attended

//--- method 1: prirotiy queue
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> que;
        sort(events.begin(), events.end());
        int i = 0, res = 0, n = events.size(), d;
        while (i < n || que.size()) {
            if (!que.size()) {
                d = events[i][0];
            }
            while (i < n && events[i][0] == d) {
                que.push(events[i++][1]);
            }
            que.pop();
            ++res;
            ++d;
            while (que.size() && que.top() < d) {
                que.pop();
            }
        }
        return res;
    }
};