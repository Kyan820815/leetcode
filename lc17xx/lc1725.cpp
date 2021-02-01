//--- Q: 1725. Number Of Rectangles That Can Form The Largest Square

//--- method 1: find max of min of rects
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxcnt = 0, maxv = 0;
        for (auto &rect: rectangles) {
            int val = min(rect[0], rect[1]);
            if (maxv < val) {
                maxv = val;
                maxcnt = 1;
            } else if (maxv == val) {
                ++maxcnt;
            }
        }
        return maxcnt;
    }
};