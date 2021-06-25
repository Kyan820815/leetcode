//--- Q: 888. Fair Candy Swap

//--- method 1: unordered_set, find pair
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma = 0, sumb = 0;
        unordered_set<int> map(A.begin(), A.end());
        for (int i = 0; i < A.size(); ++i) {
            suma += A[i];
        }
        for (int i = 0; i < B.size(); ++i) {
            sumb += B[i];
        }
        int difa = (sumb - suma) / 2;
        for (int i = 0; i < B.size(); ++i) {
            if (map.find(B[i]-difa) != map.end()) {
                return {B[i]-difa, B[i]};
            }
        }
        return {};
    }
};