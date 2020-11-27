//--- Q: 1176. Diet Plan Performance

//--- method 1: sliding window
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int sum = 0, points = 0;
        for (int i = 0; i < k; ++i) {
            sum += calories[i];
        }
        if (sum < lower) {
            --points;
        } else if (sum > upper) {
            ++points;
        }
        for (int i = k; i < calories.size(); ++i) {
            sum = sum - calories[i-k] + calories[i];
            if (sum < lower) {
                --points;
            } else if (sum > upper) {
                ++points;
            }
        }
        return points;
    }
};