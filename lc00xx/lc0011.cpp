//--- Q: 0011. Container With Most Water
//--- last written: 2023/07/01

//--- method 1: always find min idx & keep it
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                res = max(res, (right-left)*height[left++]);
            } else {
                res = max(res, (right-left)*height[right--]);
            }
        }
        return res;
    }
};
