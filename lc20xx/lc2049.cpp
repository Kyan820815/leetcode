//--- Q: 2049. Count Nodes With the Highest Score

//--- method 1: postorder recursion
class Solution {
public:
    vector<vector<int>> rel;
    using ll = long long;
    int maxres = 0, n;
    ll maxv = 0;
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        rel.resize(n);
        for (int i = 0; i < n; ++i) {
            if (parents[i] != -1) {
                rel[parents[i]].push_back(i);
            }
        }
        postorder(0);
        return maxres;
    }
    int postorder(int now) {
        int total = 0;
        ll curv = 1;
        for (auto &next: rel[now]) {
            int val = postorder(next);
            if (val) {
                curv *= val;
                total += val;
            }
        }
        int upper = n-1-total;
        if (upper) {
            curv *= upper;
        }
        if (maxv < curv) {
            maxv = curv;
            maxres = 1;
        } else if (maxv == curv) {
            ++maxres;
        }
        return total+1;
    }
};