//--- Q: 0149. Max Points on a Line

//--- method 1: 
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1) {
            return 1;
        }
        int res = 0, n = points.size();
        for (int i = 1; i < n; ++i) {
            unordered_map<int, unordered_map<int, int>> map;
            for (int j = 0; j < i; ++j) {
                int xd = points[i][0]-points[j][0];
                int yd = points[i][1]-points[j][1];
                int factor = gcd(xd, yd);
                xd /= factor;
                yd /= factor;
                if (yd < 0) {
                    xd *= -1;
                    yd *= -1;
                }
                if (map.find(xd) == map.end() || map[xd].find(yd) == map[xd].end()) {
                    map[xd][yd] = 1;
                } else {
                    ++map[xd][yd];
                }
                res = max(res, map[xd][yd]+1);
            }
        }
        return res;
    }
};