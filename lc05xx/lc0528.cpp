//--- Q; 0528. Random Pick with Weight

//--- method 1: binary search
class Solution {
public:
    Solution(vector<int>& w) {
        arr.push_back(w[0]);
        for (int i = 1; i < w.size(); ++i) {
            arr.push_back(arr.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int idx = random()%arr.back()+1;
        int left = 0, right = arr.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (arr[mid] < idx) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */