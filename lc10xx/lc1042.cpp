//--- Q: 1042. Flower Planting With No Adjacent

//--- method 1: greedy
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> rel(n);
        for (auto &path: paths) {
            rel[path[0]-1].push_back(path[1]-1);
            rel[path[1]-1].push_back(path[0]-1);
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            array<int,4> arr = {0,0,0,0};
            for (auto &next: rel[i]) {
                if (res[next]) {
                    arr[res[next]-1] = 1;
                }
            }
            for (int j = 0; j < 4; ++j) {
                if (!arr[j]) {
                    res[i] = j+1;
                    break;
                }
            }
        }
        return res;
    }
};