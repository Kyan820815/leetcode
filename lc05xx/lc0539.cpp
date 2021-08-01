//--- Q: 0539. Minimum Time Difference

//--- method 1: O(n) bucket sort
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> bucket(1440, 0);
        for (auto &time: timePoints) {
            auto h = (time[0]-'0')*10 + (time[1]-'0');
            auto m = (time[3]-'0')*10 + (time[4]-'0');
            if (++bucket[h*60+m] > 1) {
                return 0;
            }
        }
        int last = -1440, start = -1, res = 1440;
        for (int i = 0; i < 1440; ++i) {
            if (bucket[i]) {
                if (start == -1) {
                    start = i;
                }
                res = min(res, i-last);
                last = i;
            }
        }
        return min(res, start+1440-last);
    }
};

//--- method 2: O(nlogn) sort
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> arr;
        for (auto &time: timePoints) {
            auto h = (time[0]-'0')*10 + (time[1]-'0');
            auto m = (time[3]-'0')*10 + (time[4]-'0');
            arr.push_back(h*60+m);
        }
        int last = -1440, res = 1440;
        sort(arr.begin(), arr.end());
        for (auto &num: arr) {
            res = min(res, num-last);
            last = num;
        }
        return min(res, arr.front()+1440-arr.back());
    }
};