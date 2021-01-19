//--- Q: 1539. Kth Missing Positive Number

//--- method 1: binary search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (find(mid, arr) < k) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        if (find(left,arr) < k) {
            return arr[left]+k-find(left,arr);
        } else {
            if (!left) {
                return k;
            }
            return arr[left-1]+k-find(left-1,arr);
        }
    }
    int find(int idx, vector<int> &arr) {
        return arr[idx]-1-idx;
    }
};