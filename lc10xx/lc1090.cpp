//--- Q: 1090. Largest Values From Labels

//--- method 1: priority queue
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = labels.size(), res = 0;
        auto comp = [&values](int &a, int &b) {
            return values[a] < values[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> que(comp);
        for (int i = 0; i < n; ++i) {
            que.push(i);
        }
        unordered_map<int,int> cnt;
        while (que.size() && numWanted) {
            auto idx = que.top();
            que.pop();
            if (cnt[labels[idx]] < useLimit) {
                ++cnt[labels[idx]];
                --numWanted;
                res += values[idx];
            }
        }
        return res;
    }
};