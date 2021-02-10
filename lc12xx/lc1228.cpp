//--- Q: 1228. Missing Number In Arithmetic Progression

//--- method 1: O(n) search
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int idx = 0, diff = arr[1]-arr[0];
        for (int i = 1; i < arr.size()-1; ++i) {
            int curdiff = arr[i+1]-arr[i];
            if (abs(curdiff) > abs(diff)) {
                return arr[i] + curdiff/2;
            } else if (abs(curdiff) < abs(diff)) {
                return arr[0] + diff/2;
            }
        }
        return arr[0];
    }
};

//--- method 2: binary search
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int left = 0, right = arr.size()-1, d = (arr.back()-arr[0])/(int)arr.size();
        while (left < right) {
            int mid = left + (right-left)/2;
            if (arr[0]+d*mid == arr[mid]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return arr[0]+left*d;
    }
};