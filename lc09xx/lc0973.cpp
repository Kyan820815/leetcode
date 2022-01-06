//--- Q: 0973. K Closest Points to Origin

//--- method 1: priority queue
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.first*a.first+a.second*a.second < b.first*b.first+b.second*b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> que(comp);
        for (auto pt: points) {
            que.push({pt[0],pt[1]});
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<vector<int>> res;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            res.push_back({now.first, now.second});
        }
        return res;
    }
};

//--- method 2: quick select
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int start = 0, end = points.size()-1;
        k--;
        while (start < end) {
            int mid = partition(start, end, points);
            if (mid < k) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        return vector<vector<int>>(points.begin(),points.begin()+k+1);
    }
    int partition(int start, int end, vector<vector<int>> &points) {
        int pivot = start+random()%(end-start+1);
        swap(points[pivot], points[end]);
        int end_dis = points[end][0]*points[end][0]+points[end][1]*points[end][1], idx = start-1;
        for (int i = start; i < end; ++i) {
            if (points[i][0]*points[i][0]+points[i][1]*points[i][1] < end_dis) {
                swap(points[++idx], points[i]);
            }
        }
        swap(points[++idx], points[end]);
        return idx;
    }
};

//--- method 3: quick select built in
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin()+k, points.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};