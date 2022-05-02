//--- Q: 1300. Sum of Mutated Array Closest to Target

//--- method 1: binary search
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int left = 0, right = 0;
        for (auto &num: arr) {
            right = max(right, num);
        }
        int res = INT_MAX, resv = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int sum = 0;
            for (auto &num: arr) {
                sum += num < mid ? num : mid;
            }
            if (res > abs(target-sum)) {
                res = abs(target-sum);
                resv = mid;
            } else if (res == abs(target-sum) && resv > mid) {
                resv = mid;
            }
            if (sum < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return resv;
    }
};

//--- method 2: sort
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int i = 0, n = arr.size();
        while (i < n && target > arr[i]*(n-i)) {
            target -= arr[i++];
        }
        return i == n ? arr[n-1] : int(round((target-0.0001)/(n-i)));
    }
};