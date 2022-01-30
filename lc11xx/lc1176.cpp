//--- Q: 1176. Diet Plan Performance

//--- method 1: sliding window
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int points = 0, val = 0;
        for (int i = 0; i < k; ++i) {
            val += calories[i];
        }
        for (int i = k; i <= calories.size(); ++i) {
            if (val < lower) {
                --points;
            } else if (val > upper) {
                ++points;
            }
            if (i == calories.size()) {
                break;
            }
            val += calories[i] - calories[i-k];
        }
        return points;
    }
};