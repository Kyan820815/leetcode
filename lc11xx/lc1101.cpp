//--- Q: 1101. The Earliest Moment When Everyone Become Friends

//--- method 1: union find，union by size
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<int> parent(N, -1);
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        for (int i = 0; i < logs.size(); ++i) {
            int ap = findp(logs[i][1], parent);
            int bp = findp(logs[i][2], parent);
            if (ap != bp) {
                if (-parent[ap] > -parent[bp]) {
                    swap(ap, bp);
                }
                parent[bp] += parent[ap];
                parent[ap] = bp;
                if (-parent[bp] == N) {
                    return logs[i][0];
                }
            }
        }
        return -1;
    }
    int findp(int now, vector<int> &parent) {
        return parent[now] < 0 ? now : parent[now] = findp(parent[now], parent);
    }
};

//--- method 2: normal union find
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        vector<int> parent(N, -1);
        for (int i = 0; i < logs.size(); ++i) {
            int ap = findp(logs[i][1], parent);
            int bp = findp(logs[i][2], parent);
            if (ap != bp) {
                parent[ap] = bp;
                --N;
            }
            if (N == 1) {
                return logs[i][0];
            }
        }
        return -1;
        
    }
    int findp(int now, vector<int> &parent) {
        if (parent[now] != now) {
            return parent[now] == -1 ? now : findp(parent[now], parent);
        }
        return now;
    }
};