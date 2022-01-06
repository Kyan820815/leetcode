//--- Q: 0969. Pancake Sorting

//--- method 1: find max
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for (int i = n-1; i > 0; --i) {
            int maxi, maxv = INT_MIN;
            for (int j = 0; j <= i; ++j) {
                if (maxv < arr[j]) {
                    maxv = arr[j];
                    maxi = j;
                }
            }
            if (maxi < i) {
                res.push_back(maxi+1);
                res.push_back(i+1);
                reverse(arr.begin(), arr.begin()+maxi+1);
                reverse(arr.begin(), arr.begin()+i+1);
            }
        }
        return res;
    }
};