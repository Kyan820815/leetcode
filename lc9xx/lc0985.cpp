//--- Q: 985. Sum of Even Numbers After Queries

//--- method 1: track even sum
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int even = 0;
        vector<int> res;
        for (int i = 0; i <  A.size(); ++i) {
            if (!(A[i]&1)) {
                even += A[i];
            } 
        }
        for (int i = 0; i < queries.size(); ++i) {
            int idx = queries[i][1], val = queries[i][0];
            if (!(A[idx]&1)) {
                even -= A[idx];
            }
            A[idx] += val;
            if (!(A[idx]&1)) {
                even += A[idx];
            }
            res.push_back(even);
        }
        return res;
    }
};