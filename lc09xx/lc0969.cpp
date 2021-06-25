//--- Q: Pancake Sorting

//--- method 1: find max
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int swap = A.size();
        vector<int> res;
        while (swap) {
            int maxv = INT_MIN, maxidx;
            for (int i = 0; i < swap; ++i) {
                if (maxv < A[i]) {
                    maxv = A[i];
                    maxidx = i;
                }
            }
            if (maxidx != swap-1) {
                res.push_back(maxidx+1);
                res.push_back(swap);
                reverse(A.begin(), A.begin()+maxidx+1);
                reverse(A.begin(), A.begin()+swap);
            }
            --swap;
        }
        return res;
    }
};