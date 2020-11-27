//--- Q: 378. Kth Smallest Element in a Sorted Matrix

//--- method 1: partition, O(n)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
 		return divide(matrix, 0, matrix.size()*matrix[0].size()-1, k-1);
    }
    int divide(vector<vector<int>> &matrix, int left, int right, int k)
    {
    	int col = matrix[0].size();
    	int mid = partition(matrix, left, right, col);
    	if (k == mid)
    		return matrix[mid/col][mid%col];
    	else if (k < mid)
    		return divide(matrix, left, mid-1, k);
    	else
    		return divide(matrix, mid+1, right, k);
    }
    int partition(vector<vector<int>> &matrix, int left, int right, int col)
    {	
    	int pivot = rand() % (right-left+1) + left;
    	int pr, pc;
    	swap(matrix[right/col][right%col], matrix[pivot/col][pivot%col]);
    	pr = right/col, pc = right%col;
    	int mid = left-1;

    	for (int i = left; i <right; ++i)
    	{
    		int r = i/col, c = i%col;
    		if (matrix[r][c] < matrix[pr][pc])
    		{
    			mid++;
    			swap(matrix[r][c], matrix[mid/col][mid%col]);
    		}
    	}
    	mid++;
    	swap(matrix[pr][pc], matrix[mid/col][mid%col]);
    	return mid;
    }
};

//--- method 2: priority queue, O(klogN)
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
