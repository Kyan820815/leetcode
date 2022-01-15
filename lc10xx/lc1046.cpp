//--- Q: 1046. Last Stone Weight

//--- method 1: priority queue
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que(stones.begin(), stones.end());
        while (que.size() > 1) {
            auto first = que.top();
            que.pop();
            auto second = que.top();
            que.pop();
            que.push(first-second);
        }
        return que.top();
    }
};