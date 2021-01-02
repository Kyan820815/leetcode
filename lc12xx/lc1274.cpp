//--- Q: 1274. Number of Ships in a Rectangle

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */


//--- method 1:
class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (bottomLeft[1] > topRight[1] || bottomLeft[0] > topRight[0] || !sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (topRight == bottomLeft) {
            return 1;
        }
        int midx = (topRight[0] + bottomLeft[0])/2;
        int midy = (topRight[1] + bottomLeft[1])/2;
        return countShips(sea, {midx,midy}, bottomLeft)
            +  countShips(sea, topRight, {midx+1, midy+1})
            +  countShips(sea, {midx,topRight[1]}, {bottomLeft[0],midy+1})
            +  countShips(sea, {topRight[0],midy}, {midx+1, bottomLeft[1]});
    }
};
