//--- Q: 1010. Pairs of Songs With Total Durations Divisible by 60

//--- method 1: map with two sum
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0; i < time.size(); ++i) {
            time[i] %= 60;
            int now = (60 - time[i]) % 60;
            if (map.find(now) != map.end()) {
                res += map[now];
            }
            ++map[time[i]];
        }
        return res;
    }
};
