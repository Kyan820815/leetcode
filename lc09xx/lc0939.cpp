//--- Q: 939. Minimum Area Rectangle

//--- method 1: brute force
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int res = INT_MAX;
        set<pair<int, int>> set;
        for (int i = 0; i < points.size(); ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (auto &p: set) {
                auto x2 = p.first, y2 = p.second;
                if (x1 == x2 || y1 == y2) {
                    continue;
                }
                if (set.find({x1, y2}) != set.end() && set.find({x2, y1}) != set.end()) {
                    res = min(res, abs(x2-x1) * abs(y2-y1));
                }
            }
            set.insert({x1,y1});
        }
        return res == INT_MAX ? 0 : res;
    }
};

//--- method 2: sort x then save {y1, y2} = x，sliding window。
class Solution {
public:
    struct hash_pair { 
        template <class T1, class T2> 
        size_t operator()(const pair<T1, T2>& p) const
        { 
            auto hash1 = hash<T1>{}(p.first); 
            auto hash2 = hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    };
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> x2y;
        unordered_set<int> setx, sety;
        unordered_map<pair<int, int>, int, hash_pair> seen;
        int nx, ny, res = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            setx.insert(points[i][0]);
            sety.insert(points[i][1]);
        }
        // all points lie in a line.        
        if (nx == points.size() || ny == points.size()) {
            return 0;
        }
        // save computation time by reduce execution in inner double for loop
        if (nx > ny) {
            for (int i = 0; i < points.size(); ++i) {
                x2y[points[i][0]].push_back(points[i][1]);
            }
        } else {
            for (int i = 0; i < points.size(); ++i) {
                x2y[points[i][1]].push_back(points[i][0]);
            }
        }
        // compute area by small x to larget x
        // update each {y1,y2} for each x, like sliding window
        for (auto &p: x2y) {
            auto x = p.first;
            // only sort for one time
            auto yp = p.second;
            sort(yp.begin(), yp.end());
            // loop for p[x]
            for (auto y1 = yp.begin(); y1 != yp.end(); ++y1) {
                for (auto y2 = yp.begin(); y2 != y1; ++y2) {
                    if (*y1 == *y2) {
                        continue;
                    }
                    if (seen.find({*y1, *y2}) != seen.end()) {
                        int lastx = seen[{*y1, *y2}];
                        res = min(res, (x-lastx) * (*y1-*y2));
                    }
                    seen[{*y1, *y2}] = x;
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
