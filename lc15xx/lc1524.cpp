//--- Q: 1524. Number of Sub-arrays With Odd Sum

//--- method 1: odd & even
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7, res = 0, n = arr.size();
        int oddc = 0, evenc = 0;
        for (int i = 0; i < n; ++i) {
            int loddc = oddc, levenc = evenc;
            if (arr[i]&1) {
                evenc = loddc;
                oddc = levenc+1;
            } else {
                evenc = levenc+1;
                oddc = loddc;
            }
            res = (res+oddc)%mod;
        }
        return res;
    }
};

//--- follow up: total sum of odd subarrays
class Solution {
public:
    int sumOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7, res = 0, n = arr.size();
        int oddc = 0, evenc = 0, odd = 0, even = 0;
        for (int i = 0; i < n; ++i) {
            int loddc = oddc, levenc = evenc;
            int lodd = odd, leven = even;
            if (arr[i]&1) {
                even = lodd+loddc*arr[i];
                evenc = loddc;
                odd = leven+levenc*arr[i]+arr[i];
                oddc = levenc+1;
            } else {
                even = leven+levenc*arr[i]+arr[i];
                evenc = levenc+1;
                odd = lodd+loddc*arr[i];
                oddc = loddc;
            }
            res = (res+odd)%mod;
        }
        return res;
    }
};