//--- Q: 2170. Minimum Operations to Make the Array Alternating

//--- method 1: dp, maintain max cnt of value in both odd and even index
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt[100001][2] = {0};
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ++cnt[nums[i]][i&1];
        }
        int oddmax = 0, evenmax = 0, maxcnt = 0;
        for (int i = 1; i <= 100000; ++i) {
            maxcnt = max(maxcnt, max(oddmax+cnt[i][0], evenmax+cnt[i][1]));
            evenmax = max(evenmax, cnt[i][0]);
            oddmax = max(oddmax, cnt[i][1]);
        }
        return n - maxcnt;
    }
};

//--- method 2: greedy, naive way to find top 2 frequencies number
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> odd(100001, 0);
        vector<int> even(100001, 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (i&1) {
                ++odd[nums[i]];
            } else {
                ++even[nums[i]];
            }
        }
        vector<int> oddset, evenset;
        for (int i = 1; i <= 100000; ++i) {
            if (odd[i]) {
                oddset.push_back(i);
            }
            if (even[i]) {
                evenset.push_back(i);
            }
        }
        sort(oddset.begin(), oddset.end(), [&odd](const int &a, const int &b){
            return odd[a] > odd[b];
        });
        sort(evenset.begin(), evenset.end(), [&even](const int &a, const int &b){
            return even[a] > even[b];
        });
        int n = nums.size(), res = INT_MAX;
        int i = 0, j = 0, evenc = evenset.size(), oddc = oddset.size();
        int evenTotal = n/2 + (n&1);
        int oddTotal = n/2;
        
        if (nums.size() == 1) {
            return 0;
        }
        if (evenset[i] != oddset[j]) {
            return evenTotal-even[evenset[i]]+oddTotal-odd[oddset[j]];
        } else {
            int res = INT_MAX;
            if (i+1 < evenc) {
                res = min(res, evenTotal-even[evenset[i+1]]+oddTotal-odd[oddset[j]]);
            } else {
                res = min(res, evenTotal+oddTotal-odd[oddset[j]]);
            }
            if (j+1 < oddc) {
                res = min(res, evenTotal-even[evenset[i]]+oddTotal-odd[oddset[j+1]]);
            } else {
                res = min(res, evenTotal-even[evenset[i]]+oddTotal);
                
            }
            return res;
        }
        
    }
};