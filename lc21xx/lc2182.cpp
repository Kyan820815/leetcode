//--- Q: 2182. Construct String With Repeat Limit

//--- method 1: greedy bucket
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26, 0);
        for (auto &c: s) {
            ++cnt[c-'a'];
        }
        int last = 26, lcnt;
        string res = "";
        for (int i = 25; i >= 0; --i) {
            if (!cnt[i]) {
                continue;
            }
            if (last == 26) {
                lcnt = min(cnt[i], repeatLimit);
                res += string(lcnt, i+'a');
                cnt[i] -= lcnt;
                last = i;
            } else {
                while (cnt[last] && cnt[i]) {
                    lcnt = min(cnt[last], repeatLimit);
                    --cnt[i];
                    cnt[last] -= lcnt;
                    res += string(1, i+'a');
                    res += string(lcnt, last+'a');
                }
                if (!cnt[last] && !cnt[i]) {
                    last = 26;
                } else if (!cnt[last]) {
                    lcnt = min(cnt[i], repeatLimit);
                    res += string(lcnt, i+'a');
                    cnt[i] -= lcnt;
                    last = !cnt[i] ? 26 : i;
                } 
            }
        }
		return res;
    }
};

//--- method 2: max priority queue
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26, 0);
        for (auto &c: s) {
            ++cnt[c-'a'];
        }
        priority_queue<int> que;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                que.push(i);
            }
        }
        int last = 0;
        string res = "";
        while (que.size()) {
            auto now = que.top();
            que.pop();
            if (last) {
                if (!que.size()) {
                    break;
                }
                auto one = que.top();
                res += string(1, one+'a');
                if (!--cnt[one]) {
                    que.pop();
                }
            }
            int times = min(cnt[now], repeatLimit);
            res += string(times, now+'a');
            cnt[now] -= times;
            if (cnt[now]) {
                last = 1;
                que.push(now);
            } else {
                last = 0;
            }
        }
		return res;
    }
};