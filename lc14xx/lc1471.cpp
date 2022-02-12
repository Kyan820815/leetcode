//--- Q: 1471. The k Strongest Values in an Array

//--- method 1: two pointers
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), median = arr[(n-1)/2], left = 0, right = n-1;
        vector<int> res;
        while (k--) {
            if (median-arr[left] > arr[right]-median) {
                res.push_back(arr[left++]);
            } else {
                res.push_back(arr[right--]);
            }
        }
        return res;
    }
};

//--- method 2: two pointers with erase
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), median = arr[(n-1)/2], left = 0, right = n-1;
        vector<int> res;
        while (k--) {
            if (median-arr[left] > arr[right]-median) {
                ++left;
            } else {
                --right;
            }
        }
        arr.erase(arr.begin()+left, arr.begin()+right+1);
        return arr;
    }
};