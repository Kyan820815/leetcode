//--- Q: 1025. Divisor Game

//--- method 1: find regular pattern
class Solution {
public:
    bool divisorGame(int n) {
        return !(n&1);
    }
};

//--- method 2: dfs recursion
class Solution {
public:
    vector<int> visit;
    bool divisorGame(int n) {
        visit.resize(n+1, -1);
        return dfs(n);
    }
    int dfs(int now) {
        if (visit[now] != -1) {
            return visit[now];
        }
        if (now == 1) {
            return visit[1] = 0;
        }
        for (int i = 1; i < now; ++i) {
            if (now%i == 0 && !dfs(now-i)) {
                return visit[now] = 1;
            }
        }
        return visit[now] = 0;
    }
};
