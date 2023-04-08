//--- Q: 0042. Trapping Rain Water
//--- last written: 2023/03/14

//--- method 1: double pointer left & right
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                int minv = height[left++];
                while (left < right && height[left] < minv) {
                    res += minv-height[left++];
                }
            } else {
                int minv = height[right--];
                while (left < right && height[right] < minv) {
                    res += minv-height[right--];
                }
            }
        }
        return res;
    }
};

//--- method 2: stack
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> sk = {-1};
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (sk.back() != -1 && height[sk.back()] < height[i]) {
                int mid = sk.back();
                sk.pop_back();
                if (sk.back() != -1) {
                    res += (min(height[sk.back()], height[i])-height[mid])*(i-sk.back()-1);
                }
            }
            sk.push_back(i);
        }
        return res;
    }
};
