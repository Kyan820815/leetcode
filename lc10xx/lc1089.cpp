//--- Q: 1089. Duplicate Zeros

//--- method 1: O(n) time, O(1) space
class Solution {
public:
    void duplicateZeros(vector<int>& A) {
        int n = A.size(), j = n + count(A.begin(), A.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n)
                A[j] = A[i];
            if (A[i] == 0 && --j < n)
                A[j] = 0;
        }
    }
};

//--- method 2: insert
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
    	int idx = 0;
    	while (idx < arr.size())
    	{
    		if (arr[idx] == 0)
    		{
    			arr.insert(arr.begin()+idx, 0);
    			++idx;
    			arr.pop_back();
    		}
    		++idx;
    	}
    }
};