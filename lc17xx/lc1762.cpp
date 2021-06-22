//--- Q: 1762. Buildings With an Ocean View

//--- method 1: decreasing stack from left to right
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> sk;
        for (int i = 0; i < heights.size(); ++i) {
            while (sk.size() && heights[sk.back()] <= heights[i]) {
                sk.pop_back();
            }
            sk.push_back(i);
        }
        return sk;
    }
};

//--- method 2: search from right to left
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int minv = 0;
        for (int i =  heights.size()-1; i >= 0; --i) {
            if (heights[i] > minv) {
                res.push_back(i);
                minv = heights[i];
            }
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};
