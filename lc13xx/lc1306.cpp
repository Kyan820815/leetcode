//--- Q: 1306. Jump Game III

//--- method 1: bfs
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> visit(arr.size(), 0);
        visit[start] = 1;
        queue<int> que;
        que.push(start);
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (!arr[now]) {
                    return true;
                }
                if (now+arr[now] < arr.size() && !visit[now+arr[now]]) {
                    visit[arr[now]+now] = 1;
                    que.push(arr[now]+now);
                }
                if (now-arr[now] >= 0 && !visit[now-arr[now]]) {
                    visit[now-arr[now]] = 1;
                    que.push(now-arr[now]);
                }
            }
        }
        return false;
    }
};