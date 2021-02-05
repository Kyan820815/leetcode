//--- Q: 1710. Maximum Units on a Truck

//--- method 1: sort
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] > b[1];
        });
        for (int i = 0; i < boxTypes.size() && truckSize; ++i) {
            int now = min(boxTypes[i][0], truckSize);
            truckSize -= now;
            res += now*boxTypes[i][1];
        }
        return res;
    }
};