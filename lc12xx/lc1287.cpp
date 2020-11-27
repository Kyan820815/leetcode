//--- Q: 1287. Element Appearing More Than 25% In Sorted Array

//--- method 1: binary search
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> cand = {arr[0], arr[n*0.25], arr[n*0.5], arr[n*0.75]};
        for (int i = 0; i < cand.size(); ++i) {
            int l = findLast(arr, cand[i]);
            int f = findFirst(arr, cand[i]);
            if (l-f+1 > n/4) {
                return cand[i];
            }
        }
        return arr.back();
    }
    int findLast(vector<int> &arr, int target) {
        int left = 0, right = arr.size()-1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (arr[mid] <= target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
    int findFirst(vector<int> &arr, int target) {
        int left = 0, right = arr.size()-1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (arr[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

//--- method 2: linear search
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        for (int i = 0; i < arr.size()/4*3; ++i) {
            if (arr[i] == arr[i + arr.size()/4]) {
                return arr[i];
            }
        }
        return arr.back();
    }
};