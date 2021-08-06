//--- Q: 0621. Task Scheduler

//--- method 1: O(n) time, other beautiful code
clclass Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (auto &ch: tasks) {
            ++cnt[ch-'A'];
        }
        int times = 0, kinds = 0;
        for (auto &c: cnt) {
            if (c > times) {
                times = c;
                kinds = 1;
            } else if (c == times) {
                ++kinds;
            }
        }
        return max((times-1)*(n+1)+kinds, (int)tasks.size());
    }
};