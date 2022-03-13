//--- Q: 0799. Champagne Tower

//--- method 1: dp iteration
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> arr = {(double)poured};
        for (int i = 0; i < query_row; ++i) {
            vector<double> tmp(arr.size()+1, 0);
            for (int j = 0; j <= i; ++j) {
                if (arr[j] > 1) {
                    double diff = arr[j]-1;
                    arr[j] = 1;
                    tmp[j] += diff/2;
                    tmp[j+1] += diff/2;
                }
            }
            arr = tmp;
        }
        return min(1.0, arr[query_glass]);
    }
};