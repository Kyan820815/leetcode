//--- Q: 1167. Minimum Cost to Connect Sticks

//--- method 1: greedy method with priority queue
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> que(sticks.begin(), sticks.end());
        int res = 0;
        while (que.size() > 1) {
            auto first = que.top();
            que.pop();
            auto second = que.top();
            que.pop();
            res += first+second;
            que.push(first+second);
        }
        return res;
    }
};