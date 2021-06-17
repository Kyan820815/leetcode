//--- Q: 1306. Jump Game III

//--- method 1: bfs
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> que;
        que.push(start);
        while (que.size()) {
            int qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                if (!arr[now]) {
                    return true;
                }
                que.pop();
                int move = arr[now];
                arr[now] = -1;
                if (now+move < arr.size() && arr[now+move] >= 0) {
                    que.push(now+move);
                }
                if (now-move >= 0 && arr[now-move] >= 0) {
                    que.push(now-move);
                }
            }
        }
        return false;
    }
};