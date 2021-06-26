//--- Q: 1387. Sort Integers by The Power Value

//--- method 1: built-in function
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> res, map(1001, -1);
        for (int i = lo; i <= hi; ++i) {
            map[i] = dfs(i);
            res.push_back(i);
        }
        auto comp = [&map](int a, int b) {
            return map[a] < map[b] || map[a] == map[b] && a < b;
        };
        --k;
        nth_element(res.begin(), res.begin()+k, res.end(), comp);
        return res[k];
    }
    int dfs(int now) {
        if (now == 1) {
            return 0;
        }
        return (now&1 ? dfs(now*3+1) : dfs(now/2)) + 1;
    }
};

//--- method 2: quick select
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> res, map(1001, -1);
        for (int i = lo; i <= hi; ++i) {
            map[i] = dfs(i);
            res.push_back(i);
        }
        --k;
        int start = 0, end = res.size()-1;
        while (start < end) {
            int mid = partition(res, map, start, end);
            if (mid < k) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        return res[k];
    }
    int partition(vector<int> &res, vector<int> &map, int start, int end) {
        int pivot = start + random()%(end-start+1), idx = start-1;
        swap(res[pivot], res[end]);
        for (int i = start; i < end; ++i) {
            if (map[res[i]] < map[res[end]] || map[res[i]] == map[res[end]] && res[i] < res[end]) {
                swap(res[++idx], res[i]);
            }
        }
        swap(res[++idx], res[end]);
        return idx;
    }
    int dfs(int now) {
        if (now == 1) {
            return 0;
        }
        return (now&1 ? dfs(now*3+1) : dfs(now/2)) + 1;
    }
};