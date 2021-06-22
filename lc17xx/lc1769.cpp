//--- Q: 1769. Minimum Number of Operations to Move All Balls to Each Box

//--- method 1: one pass
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);
        int left_cnt = 0, left_step = 0, right_cnt = 0, right_step = 0;
        for (int i = 0, j = n-1; i < n; ++i,--j) {
            res[i] += left_step;
            res[j] += right_step;
            if (boxes[i] == '1') {
                ++left_cnt;
            }
            if (boxes[j] == '1') {
                ++right_cnt;
            }
            left_step += left_cnt, right_step += right_cnt;
        }
        return res;
    }
};