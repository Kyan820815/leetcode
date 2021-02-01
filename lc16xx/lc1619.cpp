//--- Q: 1619. Mean of Array After Removing Some Elements

//--- method 1: sort entire array
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), d = n/20, sum = 0;
        for (int i = d; i < n-d; ++i) {
            sum += arr[i];
        }
        return (double)sum/(n-d-d);
    }
};

//--- method 2: priority queue
class Solution {
public:
    double trimMean(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> minh;
        priority_queue<int, vector<int>> maxh;
        int n = arr.size(), d = n/20, sum = 0;
        for (int i = 0; i < n; ++i) {
            minh.push(arr[i]);
            if (minh.size() > d) {
                maxh.push(minh.top());
                minh.pop();
                if (maxh.size() > d) {
                    sum += maxh.top();
                    maxh.pop();
                }
            }
        }
        return (double)sum/(n-d-d);
    }
};