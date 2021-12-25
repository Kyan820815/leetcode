//--- Q: 0849. Maximize Distance to Closest Person

//--- method 1: one time pass
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int last = -1, res = 0;
        for (int i = 0; i < seats.size(); ++i) {
            if (!seats[i]) {
                continue;
            }
            if (last == -1) {
                res = max(res, i-last-1);
            } else {
                int mid = last + (i-last)/2;
                res = max(res, mid-last);
            }
            last = i;
        }
        return max(res,(int)seats.size()-last-1);
    }
};