//--- Q: 1094. Car Pooling

//--- method 1: O(n) traversal
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cap(1001, 0);
        for (int i = 0; i < trips.size(); ++i) {
            cap[trips[i][1]] += trips[i][0];
            cap[trips[i][2]] -= trips[i][0];
        }
        int people = 0;
        for (int i = 0; i <= 1000 && people <= capacity; ++i) {
            people += cap[i];
        }
        return people <= capacity;
    }
};