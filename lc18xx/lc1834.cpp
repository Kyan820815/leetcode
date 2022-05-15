//--- Q: 1834. Single-Threaded CPU

//--- method 1: min heap
class Solution {
public:
    using ll = long long;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> idx(tasks.size()), res;
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&tasks](const int &a, const int &b){
            return tasks[a][0] < tasks[b][0] 
                || tasks[a][0] == tasks[b][0] && tasks[a][1] < tasks[b][1];
        });
        auto comp = [&idx, &tasks](const int &a, const int &b) {
            return tasks[idx[a]][1] > tasks[idx[b]][1] 
                || tasks[idx[a]][1] == tasks[idx[b]][1] && idx[a] > idx[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> que(comp);
        ll time = 0;
        int curi = 0;
        while (curi < idx.size()) {
            time = tasks[idx[curi]][0];
            que.push(curi++);
            while (que.size()) {
                int now = que.top();
                que.pop();
                time += tasks[idx[now]][1];
                res.push_back(idx[now]);
                while (curi < idx.size() && tasks[idx[curi]][0] <= time) {
                    que.push(curi++);
                }
            }
        }
        return res;
    }
};