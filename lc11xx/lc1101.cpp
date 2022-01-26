//--- Q: 1101. The Earliest Moment When Everyone Become Friends

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        parent.resize(n, -1);
        for (auto &log: logs) {
            int ap = findp(log[1]);
            int bp = findp(log[2]);
            if (ap != bp) {
                parent[ap] = bp;
                if (--n == 1) {
                    return log[0];
                }
            }
        }
        return -1;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return parent[now];
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};

//--- method 2: union find，union by size
class Solution {
public:
    vector<int> parent;
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        parent.resize(n, -1);
        for (auto &log: logs) {
            int ap = findp(log[1]);
            int bp = findp(log[2]);
            if (ap != bp) {
                if (-parent[ap] > -parent[bp]) {
                    swap(ap, bp);
                }
                parent[bp] += parent[ap];
                parent[ap] = bp;
                if (parent[bp] == -n) {
                    return log[0];
                }
            }
        }
        return -1;
    }
    int findp(int now) {
        if (parent[now] < 0) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};