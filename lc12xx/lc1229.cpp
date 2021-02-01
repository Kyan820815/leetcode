//--- Q: 1229. Meeting Scheduler

//--- method 1: two pointer
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int n = slots1.size(), m = slots2.size(), i = 0, j = 0;
        while (i < n && j < m) {
            if (slots1[i][0] > slots2[j][1]) {
                ++j;
            } else if (slots2[j][0] > slots1[i][1]) {
                ++i;
            } else {
                int start = max(slots1[i][0], slots2[j][0]);
                int end = min(slots1[i][1], slots2[j][1]);
                if (end-start >= duration) {
                    return {start, start+duration};
                }
                if (slots1[i][1] > slots2[j][1]) {
                    ++j;
                } else {
                    ++i;
                }
            }
        }
        return vector<int>({});
    }
};

