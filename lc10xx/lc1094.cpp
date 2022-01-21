//--- Q: 1094. Car Pooling

//--- method 1: O(n) traversal
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> location(1001, 0);
        int people = 0;
        for (auto &trip: trips) {
            location[trip[1]] += trip[0];
            location[trip[2]] -= trip[0];
        }
        for (int i = 0; i <= 1000; ++i) {
            people += location[i];
            if (people > capacity) {
                return false;
            }
        }
        return true;
    }
};

//--- method 2: map traversal
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int people = 0;
        map<int,int> loc;
        for (auto &trip: trips) {
            loc[trip[1]] += trip[0];
            loc[trip[2]] -= trip[0];
        }
        for (auto &node: loc) {
            people += node.second;
            if (people > capacity) {
                return false;
            }
        }
        return true;
    }
};