//--- Q: 2001. Number of Pairs of Interchangeable Rectangles

//--- method 1: gcd
class Solution {
public:
    using ll = long long;
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string, ll> map;
        ll res = 0;
        for (auto &rectangle: rectangles) {
            int g = gcd(rectangle[0], rectangle[1]);
            string tag = to_string(rectangle[0]/g) + "_" + to_string(rectangle[1]/g);
            res += map[tag]++;
        }
        return res;
    }
};