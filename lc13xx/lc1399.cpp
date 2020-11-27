//--- Q: 1399. Count Largest Group

//--- method 1: count digit
class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> group(37, 0);
        int cnt, maxv = -1;
        for (int i = 1; i <= n; ++i) {
            int now = i, tmp = 0;
            while (now) {
                tmp += now % 10;
                now /= 10;
            }
            ++group[tmp];
        }
        for (int i = 1; i <= 36; ++i) {
            if (maxv < group[i]) {
                cnt = 1;
                maxv = group[i];
            } else if (maxv == group[i]) {
                ++cnt;
            }
        }
        return cnt;
    }
};