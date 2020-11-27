//--- Q: 1450. Number of Students Doing Homework at a Given Time

//--- method 1: simple O(n)
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
               ++res;
            }
        }
        return res;
    }
};