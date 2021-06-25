//--- Q: 356. Line Reflection

//--- method 1: O(n) find max and min of x
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_set<string> set;
        int maxx = INT_MIN, minx = INT_MAX;
        for (auto &point: points) {
            string str = to_string(point[0]) + "_" + to_string(point[1]);
            set.insert(str);
            maxx = max(maxx, point[0]);
            minx = min(minx, point[0]);
        }
        int total = maxx+minx;
        for (auto &point: points) {
            string str = to_string(total-point[0]) + "_" + to_string(point[1]);
            if (set.find(str) == set.end()) {
                return false;
            }
        }
        return true;
    }
};

//--- method 2: nlogn set
class Solution {
public:
    double mid;
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, set<int>> map;
        for (auto &point: points) {
            map[point[1]].insert(point[0]);
        }
        auto &x_vec = map.begin()->second;
        auto start = x_vec.begin(), end = prev(x_vec.end());
        mid = (double)(*start + *end)/2;
        ++start, --end;
        if (!compare(start, end, x_vec)) {
            return false;
        }
        for (auto it = next(map.begin()); it != map.end(); ++it) {
            auto &x_vec = it->second;
            auto start = x_vec.begin(), end = prev(x_vec.end());
            if (!compare(start, end, x_vec)) {
                return false;
            }
        }
        return true;
    }
    bool compare(set<int>::iterator &start, set<int>::iterator &end, set<int> &x_vec) {
        while (start != x_vec.end() && *start <= *end) {
            double idx = (double)(*start + *end)/2;
            if (idx != mid) {
                return false;
            }
            ++start, --end;
        }
        return true;        
    }
};