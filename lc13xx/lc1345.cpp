//--- Q: 1345. Jump Game IV

//--- method 1: bfs
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> map;
        int n = arr.size(), res = 0;
        vector<int> visit(n, 0);
        for (int i = 0; i < n; ++i) {
            map[arr[i]].push_back(i);
        }
        queue<int> que;
        que.push(0);
        visit[0] = 1;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (now == n-1) {
                    return res;                  
                }
                auto &vec = map[arr[now]];
                if (now+1 < n) {
                    vec.push_back(now+1);
                }
                if (now-1 >= 0) {
                    vec.push_back(now-1);
                }
                for (auto &node: vec) {
                    if (!visit[node]) {
                        que.push(node);
                        visit[node] = 1;
                    }
                }
                vec.clear();
            }
            ++res;
        }
        return 0;
    }
};