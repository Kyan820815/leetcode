//--- Q: 1385. Find the Distance Value Between Two Arrays

//--- method 1: O(n^2)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size(), n2 = arr2.size(), res = 0;
        for (int i = 0; i < n1; ++i) {
            int idx = 0;
            while (idx < n2 && abs(arr1[i]-arr2[idx]) > d) {
                ++idx;
            }
            res += idx == n2;
        }
        return res;
    }
};

//--- method 2: O(nlogn), binary search
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size(), n2 = arr2.size(), res = 0;
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (arr1[i] > arr2[j]) {
                if (arr1[i] - arr2[j] > d) {
                    ++j;
                } else {
                    ++i;
                }
            } else {
                if (arr2[j] - arr1[i] > d) {
                    ++res;
                }
                ++i;
            }
        }
        res += n1 - i;
        return res;
    }
};
