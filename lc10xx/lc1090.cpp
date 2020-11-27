//--- Q: 1090. Largest Values From Labels

//--- method 1: priority queue
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int, int> used;
        int res = 0;
        auto comp = [&values](int a, int b) {
              return values[a] < values[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> que(comp);
        for (int i = 0; i < labels.size(); ++i) {
            que.push(i);
        }
        while (que.size() && num_wanted) {
            auto now = que.top();
            que.pop();
            if (used[labels[now]]++ < use_limit) {
                res += values[now];
                --num_wanted;
            }
        }
        return res;
}
};
