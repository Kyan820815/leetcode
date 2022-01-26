//--- Q: 1124. Longest Well-Performing Interval

//--- method 1: prefix sum
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0, tiring = 0;
        unordered_map<int,int> map;
        for (int i = 0; i < hours.size(); ++i) {
            tiring += hours[i] > 8 ? 1 : -1;
            if (tiring > 0) {
                res = i+1;
            } else {
                if (map.find(tiring-1) != map.end()) {
                    res = max(res, i-map[tiring-1]);
                }
                if (map.find(tiring) == map.end()) {
                    map[tiring] = i;
                }
            }
        }
        return res;
    }
};