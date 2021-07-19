//--- Q: 0378. Kth Smallest Element in a Sorted Matrix

//--- method 1: partition, O(n)
class Solution {
public:
    int row, col;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left, right;
        row = matrix.size(), col = matrix[0].size();
        for (left = 0, right = row*col-1, --k; left < right;) {
            auto mid = partition(left, right, matrix);
            if (mid < k) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return matrix[left/col][left%col];
    }
    int partition(int left, int right, vector<vector<int>> &matrix) {
        int idx = left-1, pivot = random()%(right-left+1)+left;
        swap(matrix[pivot/col][pivot%col], matrix[right/col][right%col]);
        for (int i = left; i < right; ++i) {
            if (matrix[i/col][i%col] < matrix[right/col][right%col]) {
                ++idx;
                swap(matrix[idx/col][idx%col], matrix[i/col][i%col]);
            }
        }
        ++idx;
        swap(matrix[idx/col][idx%col], matrix[right/col][right%col]);
        return idx;
    }
};

//--- method 2: priority queue max heap
class Solution {
public:
    int row, col;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> que;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                que.push(matrix[i][j]);
                if (que.size() > k) {
                    que.pop();
                }
            }
        }
        return que.top();
    }
};