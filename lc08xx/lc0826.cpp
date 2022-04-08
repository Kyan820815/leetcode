//--- Q: 0826. Most Profit Assigning Work

//--- method 1: binary search
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> idx;
        int n = profit.size();
        for (int i = 0; i < n; ++i) {
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&difficulty](const int &a, const int &b){
            return difficulty[a] < difficulty[b];
        });
        vector<int> maxv;
        int m = 0;
        for (int i = 0; i < n; ++i) {
            m = max(m, profit[idx[i]]);
            maxv.push_back(m);
        }
        int res = 0;
        for (auto &w: worker) {
            int left = 0, right = n-1;
            while (left <= right) {
                int mid = left + (right-left)/2;
                if (difficulty[idx[mid]] <= w) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            if (right >= 0) {
                res += maxv[right];
            }
        }
        return res;
    }
};

//--- method 2: sort then linear search
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<array<int,2>> data;
        for (int i = 0; i < n; ++i) {
            data.push_back({difficulty[i], profit[i]});
        }
        sort(worker.begin(), worker.end());
        sort(data.begin(), data.end());
        int i = 0, res = 0, best = 0;
        for (auto &w: worker) {
            while (i < n && data[i][0] <= w) {
                best = max(best, data[i++][1]);
            }
            res += best;
        }
        return res;
    }
};

//--- method 3: map
