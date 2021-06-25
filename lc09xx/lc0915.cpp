//--- Q: 915. Partition Array into Disjoint Intervals

//--- method 1: O(1) space
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int res = 1, n = A.size(), curmaxv = A[0], localmaxv = A[0];
        for (int i = 1; i < A.size(); ++i) {
            if (localmaxv > A[i]) {
                res = i+1;
                localmaxv = curmaxv;
            } else {
                curmaxv = max(curmaxv, A[i]);
            }
        }
        return res;
    }
};

//--- method 2: O(n) space
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int res = 1, n = A.size(), maxv = -1;
        vector<int> minv(n+1, INT_MAX);
        for (int i = n-1; i >= 0; --i) {
            minv[i] = min(minv[i+1], A[i]);
        }
        for (int i = 0; i < A.size(); ++i) {
            maxv = max(maxv, A[i]);
            if (maxv <= minv[i+1]) {
                return i+1;                
            }
        }
        return 0;
    }
};