//--- Q: 1871. Jump Game VII

//--- method 1: bfs with visit necessary points
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> que;
        que.push(0);
        int max_start = 0, n = s.size();
        while (que.size()) {
            int qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (now == n-1) {
                    return true;
                }
                int left = max(now+minJump, max_start+1), right = min(now+maxJump, n-1);
                for (int i = left; i <= right; ++i) {
                    if (s[i] == '0') {
                        s[i] == '-1';
                        que.push(i);
                    }
                }
                max_start = right;
            }
            
        }
        return false;
    }
};

//--- method 2: dp
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), pre = 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (i >= minJump) {
                pre += dp[i-minJump];
            }
            if (i > maxJump) {
                pre -= dp[i-maxJump-1];
            }
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp.back();
    }
};