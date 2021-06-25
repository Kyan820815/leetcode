//--- Q: 845. Longest Mountain in Array

//--- method 1: two pointer
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int left = 0, right = 1, dir = -1, res = 0;
        while (right < arr.size()) {
            if (arr[right-1] > arr[right]) {
				// we climb the mountain before
                if (dir == 0) {
                    dir = 1;
                }
                if (dir == 1) {
                    res = max(res, right-left+1);
                } else {
					// not climb before, reset left to the current position
                    left = right;
                }
            } else if (arr[right-1] < arr[right]) {
			    // first climb the mountain, set left to the current position-1
                if (dir != 0) {
                    left = right-1;
                }
                dir = 0;
            } else {
				// not climb before, reset left to the current position
                left = right;
                dir = -1;
            }
            ++right;
        }
        return res;
    }
};

//--- method 2: two pointer, clean code
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0, left = 1, right = 0;
        while (left < arr.size()) {
            while (left < arr.size() && arr[left-1] >= arr[left]) {
                ++left;
            }
            right = left--;
            while (right < arr.size() && arr[right-1] < arr[right]) {
                ++right;
            }
            while (right < arr.size() && arr[right-1] > arr[right]) {
                res = max(res, right-left+1);
                ++right;
            }
            left = right;
        }
        return res;
    }
};
