//--- Q; 528. Random Pick with Weight

//--- method 1: binary search
class Solution {
public:
    Solution(vector<int>& w) {
        int n = w.size();
        sum.resize(n, 0);
        sum[0] = w[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int left = 0, right = sum.size()-1;
        int idx = rand() % sum.back() + 1;
        while (left < right) {
            int mid = (right-left)/2 + left;
            if (sum[mid] < idx) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */