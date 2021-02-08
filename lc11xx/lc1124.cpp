//--- Q: 1124. Longest Well-Performing Interval

//--- method 1: prefix sum
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> map;
        int cnt = 0, res = 0;
        for (int i = 0; i < hours.size(); ++i) {
            cnt += hours[i] > 8 ? 1 : -1;
            if (cnt > 0) {
                res = i+1;
            } else {
                if (map.find(cnt) == map.end()) {
                    map[cnt] = i;
                }
                if (map.find(cnt-1) != map.end()) {
                    res = max(res, i-map[cnt-1]);
                }
            }
        }
        return res;
    }
};