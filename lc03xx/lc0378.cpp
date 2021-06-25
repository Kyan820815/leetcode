//--- Q: 378. Kth Smallest Element in a Sorted Matrix

//--- method 1: partition, O(n)
class Solution {
public:
    int row, col, res;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        row = matrix.size(), col = matrix[0].size();
        divide(0, row*col-1, matrix, k-1);
        return res;
    }
    void divide(int left, int right, vector<vector<int>> &matrix, int k) {
        while (left < right) {
            int mid = find(left, right, matrix);
            if (mid < k) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        res = matrix[left/col][left%col];
    }
    int find(int left, int right, vector<vector<int>> &matrix) {
        int len = right-left+1, pivot = left + random()%len, idx = left-1;
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

//--- method 2: priority queue, O(nlogk)
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int> heap;

		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (heap.size() < k)
					heap.push(matrix[i][j]);
				else
				{
					if (matrix[i][j] < heap.top())
					{
						heap.pop();
						heap.push(matrix[i][j]);
					}
				}
			}
		}
		return heap.top();
	}		
};

//--- method 3: binary search
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int r = matrix.size(), c = matrix[0].size();
		int left = matrix[0][0], right = matrix[r-1][c-1];
		while (left < right)
		{
			int mid = (left+right) / 2;		
			int cnt = 0;
			for (int i = 0; i < r; ++i)
			{
				int j = c-1;
				while(j >= 0 && mid < matrix[i][j])
					j--;
				cnt = cnt + j + 1;
			}
			if (cnt < k)
				left = mid+1;
			else
				right = mid;
		}
		return left;
	}		
};
