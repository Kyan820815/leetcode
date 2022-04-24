//--- Q: 1642. Furthest Building You Can Reach

//--- method 1: min heap
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> que;
        int n = heights.size();
        for (int i = 0; i < n-1; ++i) {
            int diff = heights[i+1]-heights[i];
            if (diff > 0) {
                que.push(diff);
                if (que.size() > ladders) {
                    bricks -= que.top();
                    que.pop();
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        return n-1;
    }
};